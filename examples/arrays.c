#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swapStrings(char *a, char *b)
{
    char temp[15];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void bubble_sort_array(int array[], int size) {
    for (int i = 0; i < size -1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    puts("");
}

int main()
{
    double prices[5] = {100.0, 200.0, 300.0, 400.0, 500.0};

    printf("sizeof in bytes of array %d\n", sizeof(prices));


    int size_array = sizeof(prices) / sizeof(prices[0]);

    for(int i = 0; i < size_array; i++)
    {
        printf("prices[%d] = %.2f\n", i, prices[i]);
    }


    char x = 'X';
    char y = 'Y';

    printf("X = %c\n", x);
    printf("Y = %c\n", y);

    swap(&x, &y);

    printf("X = %c\n", x);
    printf("Y = %c\n", y);

    char myString[15] = "Iksem!"; // mache die Arrays gleicher länge sonst undefniertes verhalten auch im temp
    char myString2[15] = "Mehi!";
    printf("myString = %s\n", myString);
    printf("myString2 = %s\n", myString2);

    swapStrings(myString, myString2);
    printf("myString = %s\n", myString);
    printf("myString2 = %s\n", myString2);

    puts("++++++++++sort array++++++++++++");
    int array[5] = {5, 3, 4, 1, 2};
    int size = sizeof(array) / sizeof(array[0]);

    print_array(array, size);
    bubble_sort_array(array, size);
    print_array(array, size);

    return 0;
}
