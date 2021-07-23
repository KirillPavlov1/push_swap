#include "push.h"

void sort_a(t_a **a)
{
    int k;

    k = 0;
    if ((*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n
        && (*a)->n < (*a)->next->next->n)
        k = 1;
    if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n
        && (*a)->n < (*a)->next->next->n)
        k = 2;
    if ((*a)->n > (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
        k = 3;
    if (k == 1 || k == 2 || k == 3)
        sa(a);
}

void sort_mina2(t_a **a, t_a *a1)
{
	int i;

	if ((*a)->up > (*a)->down)
        i = (*a)->down;    
    else
         i = (*a)->up;  
    if ((*a)->up > (*a)->down)
    {
        while (i--)
        {
            rra(a);
            write(1, "rra\n", 4);
        }
    }
    else
    {
        while (i--)
        {
            ra(a);
            write(1, "ra\n", 3);
        }
    }
}

void sort_mina(t_a **a)
{
    t_a *a1;
    int min;

    a1 = *a;
    min = 2147483647;
    while ((*a)->next != a1)
    {
        if (min > (*a)->n)
            min = (*a)->n;
        (*a) = (*a)->next;
    }
    if (min > (*a)->n)
        min = (*a)->n;
    *a = a1;
    while ((*a)->n != min)
        (*a) = (*a)->next;
	sort_mina2(a, a1);
}

void remove_a(t_a **a)
{
    t_a *clone;
	t_a *begin;

	clone = *a;
	begin = *a;
	if (!*a)
		return ;
	while (clone->next != begin)
	{
		clone = clone->next;
		free(*a);
		*a = clone;
	}
	free(clone);
}

void main2(t_a **a, t_b **b, int argc, char **argv)
{
	int i;

	i = 0;
    while(++i < argc - 3)
    {
        pb(b, ft_bnew(argv[i]));
        write(1, "pb\n", 3);
    }
    i = i - 1;
    while(++i < argc)
    {
        ft_adda_back(a, ft_anew(argv[i]));
    }
    sort_a(a);
}

int main(int argc, char *argv[])
{
    t_b *b;
    t_a *a;

	if (argc < 3)	
		return (0);
    if (!(check_argv(argc, argv)))
    {
        write(1, "error\n", 6);
        return (0);
    }
	main2(&a, &b, argc, argv);
    while (b)
    {
        cleaner(&b);
        counter_b(&b);
        counter_a(&a, &b);
        move_stacks(&a, &b);
        print_commands(b);
        pa(&a, ft_anew_n(b->n));
        remove_b(&b);
    }
    counter_a2(&a);
    sort_mina(&a);
	remove_a(&a);
    return (0);
}