#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
vector<int> a[MAX];
int num[MAX], low[MAX];
bool joint[MAX]; //mảng lưu đỉnh khớp
int cur = 0;
int root_children = 0; //số con trực tiếp của nút gốc

void findArticulation(int v, int par){
    num[v] = low[v] = cur++;
    for(int u : a[v]){
        if(u == par){
            continue;
        }
        if(num[u] == -1){
            findArticulation(u, v);
            low[v] = min(low[v], low[u]);

            //ktra dkien
            if(par != -1 && low[u] >= num[v]){
                joint[v] = true;
            }
            if(par == -1) root_children++; //nếu v là nút gốc (ko co cha) thì tang số con
        }
        else low[v] = min(low[v], num[u]);
    }
    if(par == -1 && root_children > 1){
        joint[v] = true;
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
    memset(joint, false, sizeof(joint));

    for(int i = 0; i < n; i++){
        if(num[i] == -1){
            root_children = 0;
            findArticulation(i, -1);
        }
    }
    cout << "Articulation:" << endl;
    for(int i = 0; i < n; i++){
        if(joint[i]) cout << i << " ";
    }
    return 0;
}
