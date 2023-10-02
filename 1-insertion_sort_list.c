#include "sort.h"

/**
 * insertion_sort_list - Sorts alist of numbers using insertion sort
 *
 * @list: The list to be sorted
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	int n;
	listint_t *tmp;

	/* check if the list length is greater than 2 or not*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tmp = *list;
	while (tmp)
	{
		while (tmp)
		{
			if (tmp->next)
			{
				if ((tmp->n) > (tmp->next->n))
				{
					/* swap */
					n = tmp->n;
					*(int *)&tmp->n = tmp->next->n;
					*(int *)&tmp->next->n = n;

					tmp = *list;
					print_list(*list);
					break;
				}
			}
			tmp = tmp->next;
		}
	}
}
