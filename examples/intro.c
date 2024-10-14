#include <stdio.h>
#include <stdlib.h>


int add(int a, int b) {
	return a+b;
}

int main(void)
{
	int m;

	printf("%lu byte(s)\n", sizeof m);

	printf("%lu byte(s)\n", sizeof (int));

	printf("-------------------------------\n");


	int i = 23, j = 42; {
		// int i; // redecleration of i within new block
		i = 2323; // assigning the local i
		printf("%d, ", i);
		printf("%d, ", j);
	}

	printf("%d\n", i);

	char string[] = "hello world";
	char s[6];
	s[0] = 'h';

	char str[] = {'f','o','o','b','a','r','\0'};

	printf("%d", add(5,5));

	float c = 3.14159265358979323846;
	// variablen
	printf("%0.15f\n", c); // wenn man nachstellen haben möchte einfach 0.15f

	long long int l = 1234567890123456789;
	unsigned long long int n = 18446744073709551615U;

	printf("%lld\n", l);
	printf("%llu\n", n);











	return EXIT_SUCCESS;



}

