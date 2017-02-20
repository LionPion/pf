#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("|i = %i\n",    printf("%b", 5));
	printf("|i = %i\n", ft_printf("%b", 5));
}
