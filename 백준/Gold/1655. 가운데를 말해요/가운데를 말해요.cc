#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0; // 1 <= n <= 100'000

	cin >> n;

	priority_queue<int, vector<int>, greater<int>> minHeap; // min heap
	priority_queue<int, vector<int>, less<int>> maxHeap;	// max heap

	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;

		if (maxHeap.size() == minHeap.size())
			maxHeap.push(num);
		else
			minHeap.push(num);

		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())
		{
			int maxTop = maxHeap.top();
			int minTop = minHeap.top();

			maxHeap.pop();
			minHeap.pop();

			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}

		cout << maxHeap.top() << '\n';
	}

	return 0;
}