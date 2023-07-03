#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void merge(int* arr, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 0;
	int* temp = new int[r - p + 1];

	while (i <= q && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			temp[t++] = arr[i++];
		}
		else
		{
			temp[t++] = arr[j++];
		}
	}

	while (i <= q)
	{
		temp[t++] = arr[i++];
	}

	while (j <= r)
	{
		temp[t++] = arr[j++];
	}

	i = p;
	t = 0;

	while (i <= r)
	{
		v.push_back(temp[t]);
		arr[i++] = temp[t++];
	}

	delete[] temp;
}

void mergesort(int* arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		mergesort(arr, p, q);
		mergesort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 
	int k;
	cin >> n >> k;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	mergesort(arr, 0, n - 1);

	if (k <= v.size() && k >= 1)
		cout << v[k - 1] << '\n';
	else
		cout << -1 << '\n';

	return 0;
}