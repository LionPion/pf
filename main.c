#include <locale.h>
#include <stdio.h>
#include "header.h"

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("|i = %i\n",    printf("%S", L"@@"));
	printf("|i = %i\n", ft_printf("%S", L"@@"));
}
