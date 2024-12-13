#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s [-i] [-o outfile] keyword [file...]\n", program_name);
    exit(EXIT_FAILURE);
}

int contains_keyword(const char *line, const char *keyword, int ignore_case) {
    if (ignore_case) {
        // Case-insensitive search: Convert both line and keyword to lowercase
        const char *p = line;
        size_t keyword_len = strlen(keyword);
        while (*p) {
            if (strncasecmp(p, keyword, keyword_len) == 0) {
                return 1;
            }
            p++;
        }
        return 0;
    } else {
        // Case-sensitive search
        return strstr(line, keyword) != NULL;
    }
}

void process_file(FILE *input, const char *keyword, int ignore_case, FILE *output) {
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, input) != -1) {
        if (contains_keyword(line, keyword, ignore_case)) {
            fprintf(output, "%s", line);
        }
    }

    free(line);
}

int main(int argc, char *argv[]) {
    int opt;
    int ignore_case = 0;         // Default: Case-sensitive
    char *outfile = NULL;        // Default: Output to stdout
    char *keyword = NULL;        // Search keyword
    char **files = NULL;         // Input files
    int file_count = 0;

    // Parse command-line arguments
    while ((opt = getopt(argc, argv, "io:")) != -1) {
        switch (opt) {
            case 'i':
                ignore_case = 1; // Enable case-insensitive search
                break;
            case 'o':
                outfile = optarg; // Output file
                break;
            default:
                print_usage(argv[0]);
        }
    }

    // Ensure a keyword is provided
    if (optind >= argc) {
        fprintf(stderr, "Error: Missing required keyword.\n");
        print_usage(argv[0]);
    }

    keyword = argv[optind++];
    file_count = argc - optind;
    files = &argv[optind];

    // Open output stream
    FILE *output = stdout;
    if (outfile) {
        output = fopen(outfile, "w");
        if (!output) {
            fprintf(stderr, "Error: Could not open output file %s.\n", outfile);
            return EXIT_FAILURE;
        }
    }

    // If no files are provided, read from stdin
    if (file_count == 0) {
        process_file(stdin, keyword, ignore_case, output);
    } else {
        // Process each file
        for (int i = 0; i < file_count; ++i) {
            FILE *input = fopen(files[i], "r");
            if (!input) {
                fprintf(stderr, "Error: Could not open file %s.\n", files[i]);
                continue; // Move to the next file
            }
            process_file(input, keyword, ignore_case, output);
            fclose(input);
        }
    }

    // Close output stream if it was redirected
    if (outfile) {
        fclose(output);
    }

    return EXIT_SUCCESS;
}
