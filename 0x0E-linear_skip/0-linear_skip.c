#include "search.h"

/**
 * ls - linear search through a linked list
 * @prev: un comentario aleatorio
 * @exp: un comentario aleatorio
 * @value: un comentario aleatorio
 * Return: un comentario aleatorio
 */
skiplist_t *ls(skiplist_t *prev, skiplist_t *exp, int value)
{
	printf("Value found between indexes [%li] and [%li]\n",
			prev->index, exp->index);
	while (prev != exp->next)
	{
		printf("Value checked at index [%li] = [%i]\n",
				prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

/**
 * linear_skip -  searches for a value in a sorted skip list of integers
 * @list: un comentario aleatorio
 * @value: un comentario aleatorio
 * Return: un comentario aleatorio
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *exp;

	if (!list)
		return (NULL);
	exp = list;
	while (exp)
	{
		prev = exp;
		if (exp->express)
			exp = exp->express;
		else
		{
			while (exp->next)
				exp = exp->next;
			break;
		}
		printf("Value checked at index [%li] = [%i]\n", exp->index, exp->n);
		if (exp->n >= value)
			return (ls(prev, exp, value));
	}
	return (ls(prev, exp, value));
}
