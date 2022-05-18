#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_num_len(unsigned long long n, int base )
{
	int	i;

	i = 1;
	while (n >= (unsigned int) base)
	{
		i++;
		n = n / base;
	}
	return (i);
}
char	*ft_fill(uintptr_t n, char spec)
{
	int		remain;
	int		len;
	int 	base;
	char	c;
	char 	*table = "0123456789abcdef";
	char	*ptr;

	ptr = NULL;
	base = 10;
	if (spec == 'x' || spec == 'X' || spec == 'p')
		base = 16;
	else if (spec == 'o')
		base = 8;
	len = ft_num_len(n, base);
	ptr = malloc(sizeof(char) * len+1);
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		remain = n % base;
		c = table[remain];
		ptr[ft_num_len(n, base) - 1] = c;
		n = n / base;
	}
	ptr[len] = '\0';
	return (ptr);
}
int main(void)
{	
	int min = -2147483648;
	int max = 2147483647;

	long long longmin = -9223372036854775807;
	long long longmax = 9223372036854775807;
/*
	printf("len %d: %d\n", 1, ft_num_len(1, 16));
	printf("len %d: %d\n", 100, ft_num_len(100, 16));
	printf("len %d: %d\n", -1, ft_num_len(-1, 16));
	printf("len %d: %d\n", -100, ft_num_len(-100, 16));
	printf("len %d: %d\n", min, ft_num_len(min, 16));
	printf("len %d: %d\n", max, ft_num_len(max, 16));
	

	printf("len %lld: %d\n", longmin, ft_num_len(min, 16));
	printf("len %lld: %d\n", longmax, ft_num_len(max, 16));
*/
	printf("%s\n", ft_fill(longmax, 'x'));
	printf("%s\n", ft_fill(longmin, 'x'));
	printf("%s\n", ft_fill(max, 'x'));
	printf("%s\n", ft_fill(min, 'x'));
	printf("%s\n", ft_fill(-1, 'x'));
	printf("%s\n", ft_fill(-100, 'x'));
	printf("%s\n", ft_fill(1, 'x'));
	printf("%s\n", ft_fill(100, 'x'));

	printf(" %02d", 11);
	return (0);

}
