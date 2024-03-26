#include <iostream>
#include <vector>

using namespace std;

vector<bool> dp(1001, false);

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; 
	cin >> n;

	dp.resize(n + 1);

	dp[1] = true;
	dp[2] = false;
	dp[3] = true;

	for (int i = 4; i <= n; i++)
		dp[i] = (dp[i - 1] == false || dp[i - 3] == false);

	if (dp[n])
		cout << "SK" << endl;
	else
		cout << "CY" << endl;

	return 0;
}