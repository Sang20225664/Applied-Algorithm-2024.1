#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
vector<int> a[MAX];
bool visited[MAX];

void DFS(int u){
    visited[u] = true; //duyệt đến u thì đánh dấu đã đc duyệt
    cout << u << " ";
    for(int v : a[u]){
        if(!visited[v]){
            DFS(v); //duyệt v nếu v ch đc duyệt
        }
    }

void add(int u, int v){
    a[u].push_back(v);
    a[v].push_back(u);
}

int main(){
    int n, m;
    cin >> n >> m;

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        add(u, v);
    }
    DFS(0);
    return 0;
}
