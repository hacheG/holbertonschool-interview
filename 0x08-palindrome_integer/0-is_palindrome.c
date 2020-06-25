#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given integer is a palindrome
 * @n: input integer
 * Return: true or false
 */
int is_palindrome(unsigned long n)
{
	unsigned int rev = 0;

	if (n && !(n % 10))
		return (0);
	for (; n > rev; n /= 10)
		rev = (rev * 10) + n % 10;
	return (n == rev || n == (rev / 10));
}