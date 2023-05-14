
#include "libft.h"

int	ft_strcmp(char *first, char *second)
{
	int	i;

	i = 0;
	while ((first[i] != '\0' || second[i] != '\0'))
	{
		if (first[i] < second[i])
		{
			return (-1);
		}
		else if (first[i] > second[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
