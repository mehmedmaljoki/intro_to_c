#include <stdio.h>
#include <string.h>

int main()
{
    int numbers[][3] = {
                {1, 2, 3},
                {4, 5, 6},

    };

    int rows = sizeof(numbers) / sizeof(numbers[0]);
    int columns = sizeof(numbers[0]) / sizeof(numbers[0][0]);


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("numbers[%d][%d] = %d\n", i, j, numbers[i][j]);
        }
        printf("\n");

    }

    char cars[][10] = {
                "Toyota",
                "BMW",
                "Mercedes",
                "Audi",
                "Volkswagen"
    };

    strcpy(cars[0], "Tesla");

    for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
    {
        printf("cars[%d] = %s\n", i, cars[i]);
    }



    return 0;
}