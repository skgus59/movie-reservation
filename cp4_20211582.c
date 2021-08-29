#include <stdio.h>

void swap(int** np1, int** np2);

int main(void)
{
	int num1 = 10000;
	int num2 = 9000;
	int* np1 = &num1;
	int* np2 = &num2;
	printf("Before swapping\n");
	printf("\nnum1 = %d, address: %p\n", *np1, np1);
	printf("num2 = %d, address: %p\n", *np2, np2);

	swap(&np1, &np2);

	printf("\nAfter swapping\n");
	printf("\nnum1 = %d, address: %p\n", *np1, np1);
	printf("num2 = %d, address: %p\n", *np2, np2);

	return 0;
}

void swap(int** np1, int** np2)
{
	int* tmp;
	tmp = *np1;
	*np1 = *np2;
	*np2 = tmp;
}
