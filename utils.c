#include "push.h"

int				check_argv2(const char *str)
{
	long long	k;
	long long	s;
	int			i;
	int			n;

	i = 0;
	k = 0;
	n = 1;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			n = -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		s = k;
		k = k * 10 + (long long)(str[i] - '0');
		if (s > k)
			return (n == 1 ? -1 : 0);
		i++;
	}
	if (k > 2147483647)
		return (-1);
	return (2);
}

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

int check_argv3(char **argv)
{
    int i;
    int j;

    i = -1;
    j = 0;

    while (argv[++i])
    {
        while(argv[++j])
        {
            if (!ft_strcmp(argv[i], argv[j]))
                return (0);
        }
        j = i + 1;
    }
    
    return (1);
}

int check_argv(int argc, char **argv)
{
    int i;
    int j;

    j = 0;
    i = 0;

    if (!check_argv3(argv))
        return (0);
    while (++i < argc)
    {
        j = 0;
        if (check_argv2(argv[i]) != 2)
            return (0);
        while(argv[i][j])
        {
            if (argv[i][j] == '-' && j == 0)
                j++;
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (0);
            j++;
        }
    }
    return (1);
}

void remove_b(t_b **b)
{
    t_b *begin;

    begin = *b;

    while((*b)->next != begin)
    {
        (*b) = (*b)->next;
    }
    if ((*b)->next == *b && (*b)->past == *b)
    {
        free(*b);
        *b = NULL;
    }
    else
    {
        (*b)->next = begin->next;
        begin->next->past = (*b)->next;
        (*b) = begin->next;
        free(begin);
    }
}

void print_commands(t_b *b)
{
    /*if (b->down > b->up)
    {
        while(b->up--)
            write(1, "rb\n", 3);
    }
    else
    {
        while(b->down--)
            write(1, "rrb\n", 4);
    }

    if (b->down_a > b->up_a)
    {
        while(b->up_a--)
            write(1, "ra\n", 3);
    }
    else
    {
        while(b->down_a--)
            write(1, "rra\n", 4);
    }*/
	/*if (b->down > b->up && b->down_a > b->up_a)
	{
		while (b->up-- && b->up_a--)
			write(1, "rr\n", 3);
		while (b->up-- > 0)
			write(1, "rb\n", 3);
		while (b->up_a-- > 0)
			write(1, "ra\n", 3);
		b->up = 0;
		b->up_a = 0;
	}
	else if (b->down > b->up)
    {
        while(b->up--)
            write(1, "rb\n", 3);
		b->up = 0;
    }
    else
    {
        while(b->up_a--)
            write(1, "ra\n", 3);
		b->up_a = 0;
    }
	if (b->down < b->up && b->down_a < b->up_a)
	{
		while (b->down-- && b->down_a--)
			write(1, "rrr\n", 4);
		while (b->down-- > 0)
			write(1, "rrb\n", 4);
		while (b->down_a-- > 0)
			write(1, "rra\n", 4);
		b->down = 0;
		b->down_a = 0;
	}
	else if (b->down_a < b->up_a)
    {
        while(b->down_a--)
            write(1, "rra\n", 4);
		b->down_a = 0;
    }
    else
    {
        while(b->down--)
            write(1, "rrb\n", 4);
		b->down = 0;
    }*/
	if (b->down > b->up)
    {
		if (b->down_a > b->up_a)
		{
			while(b->up > 0 && b->up_a > 0)
			{
				b->up--;
				b->up_a--;
            	write(1, "rr\n", 3);
			}
		}
        while(b->up-- > 0)
            write(1, "rb\n", 3);
    }
    else
    {
		if (b->up_a > b->down_a)
		{
			while(b->down > 0 && b->down_a > 0)
			{
				b->down--;
				b->down_a--;
            	write(1, "rrr\n", 4);
			}
		}
        while(b->down-- > 0)
            write(1, "rrb\n", 4);
    }

    if (b->down_a > b->up_a)
    {
		if (b->down > b->up)
		{
			while(b->up > 0 && b->up_a > 0)
			{
				b->up--;
				b->up_a--;
            	write(1, "rr\n", 3);
			}
		}
        while(b->up_a-- > 0)
            write(1, "ra\n", 3);
    }
    else
    {
		if (b->up > b->down)
		{
			while(b->down > 0 && b->down_a > 0)
			{
				b->down--;
				b->down_a--;
            	write(1, "rrr\n", 4);
			}
		}
        while(b->down_a-- > 0)
            write(1, "rra\n", 4);
    }
    write(1, "pa\n", 3);
}

void cleaner(t_b **b)
{
    t_b *b1;

    b1 = *b;
    while((*b)->next != b1)
    {
        (*b)->up = 0;
        (*b)->down = 0;
        (*b)->down_a = 0;
        (*b)->up_a = 0;
        (*b)->sum = 0;
        (*b) = (*b)->next;
    }
    (*b)->up = 0;
    (*b)->down = 0;
    (*b)->down_a = 0;
    (*b)->up_a = 0;
    (*b)->sum = 0;
    (*b) = b1;
}

int is_biggest(t_a **a, int n, int m)
{
    t_a *a1;
    int max;

    max = -2147483648;

    a1 = *a;
    while ((*a)->next != a1)
    {
        if ((*a)->n > max)
            max = (*a)->n;
        (*a) = (*a)->next;
    }
    if ((*a)->n > max)
        max = (*a)->n;
    (*a) = a1;
    if (n > max && m == max)
        return (1);
    return (0);
}

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
	{
        sa(a);
		write(1, "sa\n", 3);
	}
}

void sort_mina2(t_a **a)
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
	sort_mina2(a);
}

void remove_a(t_a **a)
{
    t_a *begin;

    begin = *a;

    while((*a)->next != begin)
    {
        (*a) = (*a)->next;
    }
    if ((*a)->next == *a && (*a)->past == *a)
    {
        free(*a);
        *a = NULL;
    }
    else
    {
        (*a)->next = begin->next;
        begin->next->past = (*a)->next;
        (*a) = begin->next;
        free(begin);
    }
}

int first_last(char *argv[], int argc)
{
	int i;

	i = 0;
	while(++i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
	}
	return (1);
}