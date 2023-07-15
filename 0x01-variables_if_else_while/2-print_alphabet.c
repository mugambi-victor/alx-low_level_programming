#include <stdio.h>
/**
 * main- Entry point
 * Description: printing alphabet in lowercase
 * Return: 0 always
 **/
int main(void)
{
	int n = 97;

	while (n <= 122)
	{
		putchar(n);
		n++;
	}
	putchar("\n");
	return (0);
}
