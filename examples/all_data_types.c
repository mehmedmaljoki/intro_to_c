
#include <limits.h>
#include <stdint.h>
#include <stdio.h>


#define SEPERATOR "+----------------+----------+----------------------+----------------------+---------+----------------------+"

#define DESCRIBE_BASIC_TYPE(TYPE, MIN, MAX) \
    printf("| %-10s     | %8zu | %20lld | %20lld | %7llu | %20llu |\n", #TYPE, sizeof(TYPE), \
        (long long) MIN, (long long) MAX, 0llu, (unsigned long long) U ## MAX)

#define DESCRIBE_STDINT_TYPE(TYPE, MIN, MAX) \
    printf("| (u)%-10s  | %8zu | %20lld | %20lld | %7llu | %20llu |\n", #TYPE, sizeof(TYPE), \
        (long long) MIN, (long long) MAX, 0llu, (unsigned long long) U ## MAX)

int main() {
        puts(SEPERATOR "\n"
            "| Type name    | Size (B) |    Minimum (signed)  |   Maximum (signed)   |  Min (U)|  Maximum (unsigned)  |\n");

        DESCRIBE_BASIC_TYPE(char, CHAR_MIN, CHAR_MAX);
        DESCRIBE_BASIC_TYPE(short, SHRT_MIN, SHRT_MAX);
        DESCRIBE_BASIC_TYPE(int, INT_MIN, INT_MAX);
        DESCRIBE_BASIC_TYPE(long, LONG_MIN, LONG_MAX);
        DESCRIBE_BASIC_TYPE(long long, LLONG_MIN, LLONG_MAX);
        puts(SEPERATOR);
        DESCRIBE_STDINT_TYPE(int8_t, INT8_MIN, INT8_MAX);
        DESCRIBE_STDINT_TYPE(int16_t, INT16_MIN, INT16_MAX);
        DESCRIBE_STDINT_TYPE(int32_t, INT32_MIN, INT32_MAX);
        DESCRIBE_STDINT_TYPE(int64_t, INT64_MIN, INT64_MAX);
        puts(SEPERATOR);
}