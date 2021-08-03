#include "push.h"

static void main2(t_a **a, t_b **b, int argc, char **argv)
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

static void main3(t_a **a, t_b **b)
{
        cleaner(b);
        counter_b(b);
        counter_a(a, b);
        move_stacks(a, b);
        print_commands(*b);
        pa(a, ft_anew_n((*b)->n));
        remove_b(b);
}
int main(int argc, char *argv[])
{
    t_b *b;
    t_a *a;

	if (argc < 3)	
		return (0);
    if (!(check_argv(argc, argv)))
    {
        write(1, "Error\n", 6);
        return (0);
    }
	if (first_last(argv, argc))
		return (0);
	main2(&a, &b, argc, argv);
    while (b)
        main3(&a, &b);
    counter_a2(&a);
    sort_mina(&a);
	remove_a(&a);
    return (0);
}