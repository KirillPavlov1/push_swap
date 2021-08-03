#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct			s_a{
    int                 n;
	int					up;
	int					down;
    char                *argv;
	struct s_a          *past;
	struct s_a          *next;
}						t_a;

typedef struct			s_b{
    int                 n;
	int					up;
	int					down;
	int					up_a;
	int					down_a;
	int					sum;
	struct s_b          *past;
	struct s_b          *next;
}						t_b;

typedef struct			s_set{
	char				*c;
	struct s_set		*next;
}						t_set;

t_b	*ft_bnew(void *content);
void	ft_addb_back(t_b **lst, t_b *new);
void	ft_adda_back(t_a **lst, t_a *new);
t_a	*ft_anew(void *content);
void print_stacks(t_a *a, t_b *b);
int check_argv(int argc, char **argv);
int				check_argv2(const char *str);
void	pb(t_b **lst, t_b *new);
void rrb(t_b **b);
void rra(t_a **a);
void rrr(t_a **a, t_b **b);
void rb(t_b **b);
void ra(t_a **a);
void rr(t_a **a, t_b **b);
void sa(t_a **a);
void sb(t_b **b);
void ss(t_a **a, t_b **b);
void	pa(t_a **lst, t_a *new);
int	b_size(t_b *b);
int	a_size(t_a *b);
void counter_b(t_b **b);
void counter_a(t_a **a, t_b **b);
t_a	*ft_anew_n(int n);
t_b	*ft_bnew_n(int n);
void remove_b(t_b **b);
void print_commands(t_b *b);
void move_stacks(t_a **a, t_b **b);
int count_sum(t_b **b);
void cleaner(t_b **b);
int is_biggest(t_a **a, int n, int m);
void counter_a2(t_a **b);
void remove_a(t_a **a);
int first_last(char *argv[], int argc);
t_set	*ft_setnew(char *line);
void	ft_setadd_back(t_set **lst, t_set *new);
void main2(t_a **a, t_b **b, int argc, char **argv);
void sort_mina(t_a **a);
void sort_mina2(t_a **a);
void sort_a(t_a **a);
int execute_c(t_set *com, t_a **a, t_b **b);
int ft_strcmp(char *str1, char *str2);