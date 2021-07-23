#include "push.h"

void counter_b(t_b **b)
{
    t_b *b1;
    int i;

    b1 = *b;
    i = 0;
    while ((*b)->next != b1)
    {
        (*b)->up = i;
        i++;
        *b = (*b)->next;
    }
    (*b)->up = i;
    *b = b1;
    i++;
    while ((*b)->next != b1)
    {
        (*b)->down = i;
        i--;
        *b = (*b)->next;
    }
    (*b)->down = i;
    *b = b1;
}

void counter_a2(t_a **b)
{
    t_a *b1;
    int i;

    b1 = *b;
    i = 0;
    while ((*b)->next != b1)
    {
        (*b)->up = i;
        i++;
        *b = (*b)->next;
    }
    (*b)->up = i;
    *b = b1;
    i++;
    while ((*b)->next != b1)
    {
        (*b)->down = i;
        i--;
        *b = (*b)->next;
    }
    (*b)->down = i;
    *b = b1;
}

void counter_a(t_a **a, t_b **b)
{
    int num;
    t_b *b1;
    t_b *b2;
    t_a *a1;

    b1 = *b;
    a1 = *a;
    num = 2147483647;
    while((*b)->next != b1)
    {
        while((*a)->next != a1)
        {
            if ((num > (*a)->n && (*a)->n > (*b)->n) || is_biggest(a, (*b)->n, (*a)->n))
                num = (*a)->n;
            (*a) = (*a)->next;
        }
        if ((num > (*a)->n && (*a)->n > (*b)->n) || is_biggest(a, (*b)->n, (*a)->n))
            num = (*a)->n;
        (*a) = a1;
        while ((*a)->n != num)
        {
            ra(a);
            (*b)->up_a++;
        }
        if ((*b)->n > num)
		{
			ra(a);
            (*b)->up_a++;
		}
        (*a) = a1;
        while ((*a)->n != num)
        {
            rra(a);
            (*b)->down_a++;
        }
        if ((*b)->n > num)
		{	
			ra(a);
            (*b)->down_a--;
		}
		if ((*b)->down_a == -1)
			(*b)->down_a = (*b)->up_a + 1;
        (*a) = a1;
        (*b) = (*b)->next;
        num = 2147483647;
    }
        while((*a)->next != a1)
        {
            if ((num > (*a)->n && (*a)->n > (*b)->n) || is_biggest(a, (*b)->n, (*a)->n))
                num = (*a)->n;
            (*a) = (*a)->next;
        }
        if ((num > (*a)->n && (*a)->n > (*b)->n) || is_biggest(a, (*b)->n, (*a)->n))
                num = (*a)->n;
        (*a) = a1;
        while ((*a)->n != num)
        {
            ra(a);
            (*b)->up_a++;
        }
        if ((*b)->n > num)
		{
			ra(a);
            (*b)->up_a++;
		}
        (*a) = a1;
        (*a) = a1;
        while ((*a)->n != num)
        {
            rra(a);
            (*b)->down_a++;
        }
        if ((*b)->n > num)
		{
			ra(a);
            (*b)->down_a--;
		}
		if ((*b)->down_a == -1)
			(*b)->down_a = (*b)->up_a + 1;;
        (*a) = a1;
        (*b) = (*b)->next;
        num = 2147483647;
        (*b) = b1;
}