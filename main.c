#include "push.h"

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