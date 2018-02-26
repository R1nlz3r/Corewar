#include <stdio.h>

int main()
{
	int a = 42;
	int b = 12;

	if ((a != 2 && a != 4) || b != 1)
		printf("hello a = %d, b = %d\n", a, b);
	else
		return (-1);
	return (0);
}
