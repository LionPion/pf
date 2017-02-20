#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("|i = %i\n",    printf("%.3s", NULL));
	printf("|i = %i\n", ft_printf("%.3s", NULL));
}
