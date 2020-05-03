#include "ft_printf.h"
#include <stdio.h>

// last trouble is with double_neg P=aff+1
//
int main(void)
{
	/* TESTED OK __ DOUBLE_NEG
	int ret = 0;
	int ret0 = 0;
	ret = printf("pr_KI32fOkW1VSp7pY8h%-s%-15.*d\n", NULL, 10, -886621286);
	printf("pr_ret = [%d]\n", ret);
	ret0 = ft_printf("ft_KI32fOkW1VSp7pY8h%-s%-15.*d\n", NULL, 10, -886621286);
	ft_printf("ft_ret = [%d]\n", ret);
	*/
	int d = -12;
	int *p = &d;
printf("pr_-->|%-16.p|<--\n", p);
ft_printf("ft_-->|%-16.p|<--\n", p);

printf("\n");
printf("pr_-->|%-15.p|<--\n", p);
ft_printf("ft_-->|%-15.p|<--\n", p);

printf("\n");
printf("pr_-->|%-16.p|<--\n", p);
ft_printf("ft_-->|%-16.p|<--\n", p);

/*
	printf("pr_-->|%-.*%|<--\n", 1);
	ft_printf("ft_-->|%-.*%|<--\n", 1);

	printf("\n");
	printf("pr_-->|%04.3%|<--\n");
	ft_printf("ft_-->|%04.3%|<--\n");

	printf("\n");
	printf("pr_-->|%0*.%|<--\n", 2);
	ft_printf("ft_-->|%0*.%|<--\n", 2);

	printf("\n");
	printf("pr_-->|%*.%|<--\n", 3);
	ft_printf("pr_-->|%*.%|<--\n", 3);

	printf("\n");
	printf("pr_-->|%0*.%|<--\n", 3);
	ft_printf("pr_-->|%0*.%|<--\n", 3);

	printf("\n");
	printf("pr_-->|%-4.4%|<--\n");
	ft_printf("ft_-->|%-4.4%|<--\n");

	printf("\n");
	printf("pr_-->|%-4.3%|<--\n");
	ft_printf("pr_-->|%-4.3%|<--\n");

	printf("\n");
printf("neg == 1 / neg2 == 0, arg_pos == 1\n");
	printf("pr_%-15.1u\n", 0);
	ft_printf("ft_%-15.1u\n", 0);
	printf("\n");

	printf("pr_%-17.*d7S%-.4i\n", 10, -812975492, 2147483647);
	ft_printf("ft_%-17.*d7S%-.4i\n", 10, -812975492, 2147483647);
	printf("\n");

printf("neg == 1 / neg2 == 1, arg_pos == 1\n");
	printf("pr_%*.1u\n", -10, 1);
	ft_printf("ft_%*.1u\n", -10, 1);
	printf("\n");

	printf("pr_-->|%-*.3d|<--\n", -4, 198);
	ft_printf("ft_-->|%-*.3d|<--\n", -4, 198);
	printf("\n");

	printf("pr_-->|%.3d|<--\n", d);
	ft_printf("ft_-->|%.3d|<--\n", d);
	printf("\n");

	printf("pr_-->|%-*d|<--\n", -4, d);
	ft_printf("ft_-->|%-*d|<--\n", -4, d);
	printf("\n");

	printf("pr_-->|%*.d|<--\n", -4, d);
	ft_printf("ft_-->|%*.d|<--\n", -4, d);
	printf("\n");

	printf("pr_-->|%-*d|<--\n", -4, d);
	ft_printf("ft_-->|%-*d|<--\n", -4, d);

	printf("\n");
	printf("pr_-->|%-*d|<--\n", -4, d);
	ft_printf("ft_-->|%-*d|<--\n", -4, d);

	printf("\n");
	printf("pr_-->|%*.*d|<--\n", -4, 3, d);
	ft_printf("ft_-->|%*.*d|<--\n", -4, 3, d);

	printf("\n");
	printf("-->|%*.d|<--\n", -4, d);
	ft_printf("-->|%*.d|<--\n", -4, d);
*/



/*
	int ret1 = 0;
	int ret2 = 0;
	ret1 = ft_printf("ft_%-*.*d\n", 4, 3, -12);
	printf("ft_ret = %d\n", ret1);
	ret2 = printf("pr_%-*.*d\n", 4, 3, -12);
	printf("pr_ret = %d\n", ret2);

int d = -12;
printf("-->|%*.*d|<--\n", -4, 3, d);
ft_printf("-->|%*.*d|<--\n", -4, 3, d);

	int ret3 = 0;
	int ret4 = 0;
	ret3 = ft_printf("ft_-->|%-4.*i|<--\n", 3, -12);
	printf("ft_ret = %d\n", ret3);

	ret4 = printf("pr_-->|%-4.*i|<--\n", 3, -12);
	printf("pr_ret = %d\n", ret4);

	int ret5 = 0;
	int ret6 = 0;
	ret5 = ft_printf("ft_-->|%-4.2d|<--\n", -12);
	printf("ft_ret = %d\n", ret5);

	ret6 = printf("-->|%-4.2d|<--\n", -12);
	printf("pr_ret = %d\n", ret6);
*/
}
