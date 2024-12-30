#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
vector<int> a[MAX];
int num[MAX], low[MAX];
bool inStack[MAX]; //đánh dấu đỉnh đang nằm trong Stack
stack<int> s ;// lưu các đỉnh đang đc duyệt
int cur = 0;
vector<vector<int>> scc; //lưu tphan liên thông mạnh

void SCC(int u){
    num[u] = low[u] = cur++;
    s.push(u); //đưa đỉnh vào stack
    inStack[u] = true;

    for(int v : a[u]){
        if(num[v] == -1){ //neu v chua dc tham
            SCC(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v]){//Nếu v đang nằm trong Stack
            low[u] = min(low[u], num[v]);
        }
    }

    if(low[u] == num[u]){ //nếu u là đỉnh gốc của SCC
        vector<int> comp;
        while(true){
            int v = s.top(); s.pop(); //Lấy v ra khỏi stack
            inStack[v] = false;
            comp.push_back(v);
            if(v == u) break; //duyệt 1 lượt đến khi lặp
        }
        scc.push_back(comp);
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    memset(num, -1, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(inStack, false, sizeof(inStack));

    for(int i = 1; i < n; i++){
        if(num[i] == -1){
            SCC(i);
        }
    }
    cout << "SCC:" << endl;
    for(auto &c : scc){
        for(int v : c){
            cout << v << " ";
        }
        cout << endl;
    }
    cout << scc.size();
    return 0;
}
