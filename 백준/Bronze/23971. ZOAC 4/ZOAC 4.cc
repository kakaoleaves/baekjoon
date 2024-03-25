#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, n, m;
	cin >> h >> w >> n >> m;

	int row = h / (n + 1) + (h % (n + 1) != 0);
	int col = w / (m + 1) + (w % (m + 1) != 0);

	cout << row * col << '\n';


	return 0;
}