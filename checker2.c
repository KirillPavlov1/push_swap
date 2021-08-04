#include "push.h"

t_set	*ft_setnew(char *line)
{
	t_set	*new;

	new = malloc(sizeof(t_set));
	new->c = ft_strdup(line);
	new->next = NULL;
	return (new);
}

void	ft_setadd_back(t_set **lst, t_set *new)
{
	t_set	*p;

	if (lst == NULL)
		return ;
	p = *lst;
	if (p == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}
