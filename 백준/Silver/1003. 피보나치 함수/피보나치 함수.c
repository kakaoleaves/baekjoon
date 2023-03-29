#include <stdio.h>

int main()
{
	int arr0[41];
	int arr1[41];

	int n, i, arr[1000];

	arr0[0] = 1; arr0[1] = 0;
	arr1[0] = 0; arr1[1] = 1;

	for (i=2; i<41; i++){
		arr0[i] = arr0[i-1] + arr0[i-2];
		arr1[i] = arr1[i-1] + arr1[i-2];
	}
	
	scanf("%d", &n);
	for (i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	for (i=0; i<n; i++){
		int tmp = arr[i];
		printf("%d %d\n", arr0[tmp], arr1[tmp]);
	}
	
	return 0;	
}