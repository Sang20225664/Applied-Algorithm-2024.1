#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
vector<pair<int, int>> a[MAX]; //danh sách kề (đỉnh kề, trọng số)
int dis[MAX];
int n;

void init(int n){
    memset(dis, -1, sizeof(dis));
}

void DFS(int u){
    for(auto [v, w] : a[u]){
        if(dis[v] < 0){
            dis[v] = dis[u] + w;
            DFS(v);
        }
    }
}

pair<int, int> solve(int start){
    init(n);
    dis[start] = 0;
    DFS(start);

    int farthest = start;
    for(int i = 1; i <= n; i++){
        if(dis[i] > dis[farthest])
            farthest = i;
    }
    return {farthest, dis[farthest]};
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w; //cạnh u, v với trong số w
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    pair<int, int> res1 = solve(1);
    int x = res1.first; //Đỉnh xa nhất từ đỉnh 1

    pair<int, int> res2 = solve(x); //Tìm đỉnh xa nhất từ đỉnh x

    cout << res2.second;
}
