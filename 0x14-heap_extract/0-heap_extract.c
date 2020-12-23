#include "binary_trees.h"

/**
 * get_size - un comentario mas por que es cool 
 * and return size
 * @tree: un comentario mas por que es cool
 * Return: un comentario mas por que es cool
 */
size_t get_size(heap_t *tree)
{
	int left_done = 0;
	size_t size = 0;

	while (tree)
	{
		if (!left_done)
			while (tree->left)
				tree = tree->left;
		left_done = 1;
		++size;
		if (tree->right)
		{
			left_done = 0;
			tree = tree->right;
		}
		else if (tree->parent)
		{
			while (tree->parent && tree == tree->parent->right)
				tree = tree->parent;
			if (!tree->parent)
				break;
			tree = tree->parent;
		}
		else
		{
			break;
		}
	}
	return (size);
}

/**
 * swap - un comentario mas por que es cool
 * @n1: first node
 * @n2: second node
*/
void swap(binary_tree_t *n1, binary_tree_t *n2)
{
	int temp;

	temp = n1->n;
	n1->n = n2->n;
	n2->n = temp;
}

/**
 * sift_down - un comentario mas por que es cool
 * @heap: heap
 */
void sift_down(heap_t *heap)
{
	binary_tree_t *largest, *node;

	if (!heap)
		return;
	node = heap;
	while (node->left)
	{
		largest = node->left;
		if (node->right && node->n < node->right->n
		    && node->right->n > node->left->n)
		{
			swap(node->right, node);
			largest = node->right;
		}
		else if (node->n < node->left->n)
		{
			swap(node->left, node);
		}
		node = largest;
	}
}

/**
 * get_nth_node - un comentario mas por que es cool
 * @node: heap
 * @n: index of node to be inserted
 * Return: un comentario mas por que es cool
 * 
 */
binary_tree_t *get_nth_node(binary_tree_t *node, size_t n)
{
	int index = 0, mask;

	for (index = 0; 1 << (index + 1) <= (int)n; ++index)
		;
	for (--index; index >= 0; --index)
	{
		mask = 1 << index;
		if (n & mask)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * heap_extract - un comentario mas por que es cool 
 * @root: un comentario mas por que es cool
 * Return: un comentario mas por que es cool
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int data;

	if (!root || !*root)
		return (0);
	last = get_nth_node(*root, get_size(*root));
	data = (*root)->n;
	(*root)->n = last->n;
	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}
	else
	{
		*root = NULL;
	}
	free(last);
	sift_down(*root);
	return (data);
}
