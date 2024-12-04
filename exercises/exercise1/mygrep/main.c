#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


void print_usage(const char *program_name) {
    printf("Usage: %s [-i] [-o outfile] keyword [file...]\n", program_name);
}

int main(int argc, char *argv[]) {

    int opt;
    int i_flag = 0;         // track if i flag is set
    char *outfile = NULL;   // store the output file name
    char *keyword = NULL;   // required keyword argument
    char **files = NULL;    // store the list of files (Optional)
    int file_count = 0;



    while ((opt = getopt(argc, argv, "io:")) != -1) {
        switch (opt) {
            case 'i':
                i_flag = 1;
                break;
            case 'o':
                outfile = optarg;
                break;
            default:
                print_usage(argv[0]);
                return EXIT_FAILURE;
        }
    }

    // Ensure there are enough arguments after options
    if (optind >= argc) {
        fprintf(stderr, "Error: Missing required keyword.\n");
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Capture the required keyword
    keyword = argv[optind++];

    // Capture optional file arguments
    if (optind < argc) {
        file_count = argc - optind;
        files = &argv[optind];
    }

    printf("Options:\n");
    printf("  -i flag: %s\n", i_flag ? "enabled" : "disabled");
    printf("  Output file: %s\n", outfile ? outfile : "not specified");
    printf("  Keyword: %s\n", keyword);
    if (file_count > 0) {
        printf("  Files:\n");
        for (int i = 0; i < file_count; i++) {
            printf("    %s\n", files[i]);
        }
    } else {
        printf("  No files provided.\n");
    }

    // TODO: Add your program's logic here, using the parsed inputs.

    return EXIT_SUCCESS;
}
