#include "libft.h"

int	main(void)
{
	char	*str;
	int		i;

	str = ft_strcpy(ft_strnew(21), "This is a test string");
	i = 5318008;
	ft_printf("String: \"%s\"\nInt: %d\n", str, i);
	return (0);
}
