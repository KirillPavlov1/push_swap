#include "push.h"

static void	print_commands21(t_b *b)
{
	if (b->up > b->down)
	{
		while (b->down > 0 && b->down_a > 0)
		{
			b->down--;
			b->down_a--;
			write(1, "rrr\n", 4);
		}
	}
	while (b->down_a-- > 0)
		write(1, "rra\n", 4);
}

static void	print_commands2(t_b *b)
{
	if (b->down_a > b->up_a)
	{
		if (b->down > b->up)
		{
			while (b->up > 0 && b->up_a > 0)
			{
				b->up--;
				b->up_a--;
				write(1, "rr\n", 3);
			}
		}
		while (b->up_a-- > 0)
			write(1, "ra\n", 3);
	}
	else
		print_commands21(b);
}

static void	print_commands11(t_b *b)
{
	if (b->up_a > b->down_a)
	{
		while (b->down > 0 && b->down_a > 0)
		{
			b->down--;
			b->down_a--;
			write(1, "rrr\n", 4);
		}
	}
	while (b->down-- > 0)
		write(1, "rrb\n", 4);
}

void	print_commands(t_b *b)
{
	if (b->down > b->up)
	{
		if (b->down_a > b->up_a)
		{
			while (b->up > 0 && b->up_a > 0)
			{
				b->up--;
				b->up_a--;
				write(1, "rr\n", 3);
			}
		}
		while (b->up-- > 0)
			write(1, "rb\n", 3);
	}
	else
		print_commands11(b);
	print_commands2(b);
	write(1, "pa\n", 3);
}
