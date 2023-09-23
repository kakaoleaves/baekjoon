#include <iostream>
#include <vector>

using namespace std;

pair<int, int> farthestNode(int node, int parent, vector<vector<pair<int, int>>>& tree)
{
	pair<int, int> ret = {node, 0};
    for (auto& p : tree[node])
    {
		if (p.first == parent) continue;
		auto tmp = farthestNode(p.first, node, tree);
        if (ret.second < tmp.second + p.second)
        {
			ret = {tmp.first, tmp.second + p.second};
		}
	}
	return ret;
}

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
	int n; // 2 <= v <= 10000

    cin >> n;

    vector<vector<pair<int, int>>> tree(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int parent, child, weight;
		cin >> parent >> child >> weight;
		tree[parent].push_back({child, weight});
		tree[child].push_back({parent, weight});
	}

    auto x = farthestNode(1, 0, tree);
    auto y = farthestNode(x.first, 0, tree);

    cout << y.second << '\n';

    return 0;
}