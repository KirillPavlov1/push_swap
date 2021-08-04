#include "push.h"

void	check_argv20(const char *str, int *i, int *n)
{
	while (str[*i] == ' ' || str[*i] == '\v' || str[*i] == '\f'
		|| str[*i] == '\n' || str[*i] == '\t' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
		if (str[(*i)++] == '-')
			*n = -1;
}

int	check_argv2(const char *str)
{
	long long	k;
	long long	s;
	int			i;
	int			n;

	i = 0;
	k = 0;
	n = 1;
	check_argv20(str, &i, &n);
	while (str[i] <= '9' && str[i] >= '0')
	{
		s = k;
		k = k * 10 + (long long)(str[i] - '0');
		if (s > k)
		{
			if (n == 1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	if (k > 2147483647)
		return (-1);
	return (2);
}

int	check_argv3(char **argv)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (argv[++i])
	{
		while (argv[++j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (0);
		}
		j = i + 1;
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!check_argv3(argv))
		return (0);
	while (++i < argc)
	{
		j = 0;
		if (check_argv2(argv[i]) != 2)
			return (0);
		while (argv[i][j])
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
