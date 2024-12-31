//Tìm số thành phần liên thông mạnh
#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int n, m;
vector<int> a[N];
vector<int> a1[N]; //đồ thị bù (đảo ngược đồ thị gốc)

int f[N];
char color[N]; //trạng thái đỉnh (w- chưa thăm, g-đang, b-đã thăm)
int t;
int icc[N]; //chỉ số tphan liên thông mạnh của mỗi đỉnh
int ncc; //res
int x[N]; //dsach đỉnh theo thứ tự giảm dần tgian hoàn thành
int id; //chỉ số cho mảng x

//Xây đồ thị bù
void buildA1(){
    for(int u = 1; u <= n; u++){
        for(int v : a[u]){
            a1[v].push_back(u); //canhj ngược từ v đến u
        }
    }
}

//khởi tạo
void init(){
    for(int v = 1; v <= n; v++){
        color[v] = 'W'; //chưa thăm
    }
    t = 0;
}

//dfs đồ thị gốc
void dfsA(int u){
    t++;
    color[u] = 'G'; //dang tham
    for(int v : a[u]){
        if(color[v] == 'W') dfsA(v);
    }
    t++;
    f[u] = t; //ghi lại tgian hoàn thành của u
    color[u] = 'B'; //da tham
    id++;
    x[id] = u; //Luưu đỉnh u vào dsach
}

//DFS đồ thị gốc với tca thành phần
void dfsA(){
    init();
    id = 0;
    for(int v = 1; v<= n; v++){
        if(color[v] == 'W') dfsA(v);
    }
}

void dfsA1(int u){
    t++;
    color[u] = 'G';
    icc[u] = ncc;
    for(int v : a1[u]){
        if(color[v] == 'W') dfsA1(v);
    }
    color[u] = 'B';
}

void dfsA1(){
    init();
    ncc = 0;
    for(int i = n; i>= 1; i--){
        int v = x[i];
        if(color[v] == 'W'){
            ncc++;
            dfsA1(v);
        }
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
    }
    dfsA();
    buildA1();
    dfsA1();
    cout << ncc;
}
