#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	size_t	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	if (res >= (size_t)-1 / 2 && sign > 0)
		return (-1);
	if (res > (size_t)-1 / 2 && sign < 0)
		return (0);
	res *= sign;
	return ((int)res);
}
