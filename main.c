#include <stdio.h>
#include "libft.h"

int main()
{
	size_t i;
	char **tamer;

	i = 0;
	char *string = "         olol";
	tamer = ft_split(string, ' ');
	while (tamer[i])
	{
		printf("%s\n", tamer[i]);
		i++;
	}
}
