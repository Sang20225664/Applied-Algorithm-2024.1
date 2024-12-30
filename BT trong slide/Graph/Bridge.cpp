#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
vector<int> a[MAX];
int num[MAX], low[MAX];
vector<pair<int, int>> b;
int cur = 0;

void findBridges(int v, int par){
    num[v] = low[v] = ++cur; //khởi tạo

    for(int u : a[v]){
        if(u == par) continue; //bỏ qua đỉnh cha của v
        if(num[u] == -1){
            findBridges(u, v);
            low[v] = min(low[u], low[v]);
            if(low[u] > num[v]){
                b.push_back({u, v}); //công thức phát hiện cầu
            }
        }
        else{
            low[v] = min(low[v], num[u]); //nếu u đã thăm và kphai cha thì upd low
        }
    }
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(num, -1, sizeof(num));
    memset(low, 0, sizeof(low));

    for(int i = 0; i < n; i++){
        if(num[i] == -1) findBridges(i, -1); //bdau tim từ đỉnh i
    }
    cout << "Bridges: " << endl;
    for(auto i : b){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
