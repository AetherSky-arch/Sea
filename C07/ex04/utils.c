#include <unistd.h>

void	ft_putstr(char *str, int output)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(output, &str[i], 1);
		i++;
	}
}
