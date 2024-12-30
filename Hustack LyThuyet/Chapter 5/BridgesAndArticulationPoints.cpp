/*Đồ thị vô hướng N đỉnh M cạnh
Tìm tca điểm khớp nối và cầu*/

#include <bits/stdc++.h>
using namespace std;

const long N = 1e5 + 7;
const long mod = 1e9 + 7;
int n, m;
vector<int> a[N];
int cur;
int p[N], low[N], num[N], joint[N];
int child[N];
void dfs(int u){
    //Khởi tạo low, num
    cur++;
    num[u] = cur;
    low[u] = num[u];

    for(int v : a[u]){
        if(v == p[u]) continue; //nếu là nút cha thì bỏ qua
        if(num[v]){ //nếu v đã đc duyệt thì cạnh uv lúc này là cạnh ngược
            low[u] = min(low[u], num[v]);
        }
        else{
            p[v] = u;
            dfs(v); //nếu chưa duyệt thì giờ duyệt
            low[u] = min(low[u], low[v]); //cập nhật để xác định đỉnh con v có knoi ngược về tổ tiên u ko
        }
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int Articulation = 0, bridge = 0;
    cur = 0;
    for(int i = 1; i <= n; i++){
        if(!num[i]) dfs(i); //duyệt toàn bộ đthi
    }

    //tim Articulation
    memset(child, 0, sizeof(child));

    for(int i = 1; i <= n; i++){
        int v = p[i];
        if(v > 0) child[v]++; //đếm số lượng con vủa v
    }
    for(int i = 1; i <= n; i++){
        int u = p[i];
        if(u > 0 && p[u] > 0 && low[i] >= num[u]){
            joint[u] = 1; //t/m u là đỉnh khớp (u là cha, ko là gốc, ko có đường nào từ cây con quay về tổ tiên của u)
        }
    }
    for(int i = 1; i<= n; i++){ //nếu i là gốc thì phải có 2 con mới là 1 khớp
        if(p[i] == 0 && child[i] >= 2) joint[i] = 1;
    }
    for(int i = 1; i<= n; i++) Articulation += (joint[i] == 1);

    //Count Bridges
    for(int i = 1; i <= n; i++){
        if(p[i] != 0 && low[i] >= num[i])
            bridge++; //i ko lf gốc và ko có đường nối từ i quay lại tổ tiên của nó
    }
    cout << Articulation << " " << bridge;
    return 0;
}
