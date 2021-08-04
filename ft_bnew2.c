#include "push.h"

int	b_size(t_b *b)
{
	int	count;
	t_b	*b1;

	b1 = b;
	if (b == NULL)
		return (0);
	count = 1;
	while (b->next != b1)
	{
		count++;
		b = b->next;
	}
	return (count);
}

int	a_size(t_a *b)
{
	int	count;
	t_a	*b1;

	b1 = b;
	if (b == NULL)
		return (0);
	count = 1;
	while (b->next != b1)
	{
		count++;
		b = b->next;
	}
	return (count);
}
