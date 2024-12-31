/*n tpho
Giữa 2 tpho i, j có 1 đường (2 chiều)
tpho i có tuyền xe bus giá vé C[i] đến đc tối đa D[i] tpho
--> Tìm cách đi từ tpho 1 đến tpho n với ít tiền nhất
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
const int INF = 1e9;
int n, m;
int C[N], D[N];
int w[N][N]; //chi phí (trọng số trong đồ thị)
int d[N]; //kc ngắn nhất từ nguồn đến i
bool f[N]; //f[v] true nếu đường đi ngắn nhất từ nguồn đến v đc tìm thấy
vector<int> a[N];

void BFS(int i){
    queue<int> q;
    for(int j = 1; j <= n; j++) d[j] = -1; //khoảng cách ban đầu là -1 (chưa thăm)
    d[i] = 0; //tpho bdau có kc là 0
    q.push(i);
    while(!q.empty()){
        int v = q.front(); q.pop();
        w[i][v] = C[i]; //chi phí đi từ i đến v là giá vé lên xe tại i

        //Duyệt các đỉnh kề
        for(int j = 0; j < a[v].size(); j++){
            int u = a[v][j]; //đỉnh (tpho) kề
            if(d[u] >= 0) continue; //nếu đã thăm thì bỏ qua
            d[u] = d[v] + 1;
            if(d[u] <= D[i]) q.push(u); //nếu đi được đến u (trong phạm vi cho phép)
        }
    }
}

void dijkstra(int s, int t){
    for(int v = 1; v <= n; v++){ d[v] = w[s][v]; f[v] = false;}
    d[s] = 0; f[s] = true;
    for(int i = 1; i <= n; i++){
        int u = -1; int minD = INF;
        // select a node u having minimum d[u]
        for(int v = 1; v <= n; v++) if(!f[v]){
            if(d[v] < minD){ u = v; minD = d[v]; }
        }
        f[u] = true;
        if(u == t) break; // the result was found
        for(int v = 1; v <= n; v++) if(!f[v]){
            if(d[v] > d[u] + w[u][v]){
                d[v] = d[u] + w[u][v];
            }
        }
    }
    cout << d[t];
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> C[i] >> D[i];
    }
    while(m--){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            w[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++) BFS(i);
    dijkstra(1, n);
    return 0;
}
