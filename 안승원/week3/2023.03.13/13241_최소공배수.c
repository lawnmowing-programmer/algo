#include <stdio.h>

int	gcd(int a, int b)
{
	int tmp;
	while (b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return (a);
}

int main(void)
{
	long long int	a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", a * b / gcd(a, b));
	return (0);
}
