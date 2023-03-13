#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

bool isPrime(int n)
{
	if (n == 1 || n <= 0) return false;	

	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;

	return true;
}


int main()
{
	int n, num, count = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (isPrime(num)) ++count;
	}

	printf("%d", count);

	return 0;
}