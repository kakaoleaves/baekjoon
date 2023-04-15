#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v[100001];
int a[100001],vis[100001];

void go(int here){
    vis[here] = 1;
    for(int there : v[here]){
        if(vis[there]) continue;
        a[there] = here;
        go(there);
    }

}
int main(){
    cin >> n;

    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    go(1);
    for(int i=2; i<=n; i++) cout << a[i] << '\n';
}