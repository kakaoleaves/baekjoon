#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getPreOrder(vector<int>& inorder, vector<int>& postorder, int ioStart, int ioEnd, int poStart, int poEnd){
    if (ioStart > ioEnd || poStart > poEnd)
		return;

    int root = postorder[poEnd];
    int ioRootIdx = (int) distance(inorder.begin(), find(inorder.begin() + ioStart, inorder.begin() + ioEnd, root));

    cout << root << " ";
    getPreOrder(inorder, postorder, ioStart, ioRootIdx - 1, poStart, poStart + ioRootIdx - ioStart - 1);
    getPreOrder(inorder, postorder, ioRootIdx + 1, ioEnd, poStart + ioRootIdx - ioStart, poEnd - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> inorder(n);
    vector<int> postorder(n);

    for (auto& e : inorder)
        cin >> e;
    for (auto& e : postorder)
        cin >> e;

    getPreOrder(inorder, postorder, 0, n - 1, 0, n - 1);

    return 0;
}