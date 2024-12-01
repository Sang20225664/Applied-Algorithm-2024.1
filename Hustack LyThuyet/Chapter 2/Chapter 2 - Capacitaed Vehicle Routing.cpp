#include <bits/stdc++.h>
using namespace std;
#define max_n 20
#define max_k 10

int n, K, q;
int d[11]; //so hang can giao cho khach i
int c[31][31]; //mtr kcach
int y[max_n]; //y[k] -> kh dau tien trong lo trinh cua xe k
int x[max_n]; //x[v] -> diem tiep theo sau v trong lo trinh
bool visited[max_n] = {false}; //cac khach hang da duoc phuc vu
int load[max_n]; //load[k] -> tai htai cua xe k
int segment; //tong so diem trong tca cac lo trinh
int cmin = 1e9 + 1 ; //kc nho nhat tim duoc
int curdis = 0; //tong kc htai trong lo trinh
int mindis = 1e9; //kc nho nhat giua 2 diem bat ki
int cus; //so luong khach hang trong tca cac lo trinh
int s = 0; //chi so bdau cua khach hang

void input(){
    cin >> n >> K >> q;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
            if(i != j) mindis = min(mindis, c[i][j]);
        }
        y[0] = 0; //lo trinh bdau tu kho
    }
}
//ktra xe k co the di chuyen tu u den v duoc khong
bool checkX(int v, int u, int k){
    if(visited[v] == true && v > 0) return false; //v da dc phuc vu
    if(load[k] + d[v] > q) return false; //khong du trong tai
}

void tryX(int u, int k){
    if(u == 0) { //neu da quay lai diem bdau
        if(k < k) tryX(y[k+1], k+1); //thu tiep neu con xe chua di
        return;
    }
    for(int v = 0; v<= n; v++){
    if(checkX(v, u, k)){
        x[u] = v;
        visited[v] = true;
        load[k] += d[v];
        segment ++;
        curdis += c[u][v];
        if(v == 0){
            if(k == K){
                if(segment == n + cus){ //neu tca kh da duoc tham
                    if(cmin > curdis) cmin = curdis; //cap nhat khoang cach toi thieu
                }
            }
            else{
                if(curdis + ( n + cus - segment) * mindis < cmin) tryK(y[k+1], k+ 1);
            }
        } else{
            if(cusdis + (n + cus - segment) * mindis < cmin) tryK(v, k);
        }
    }
}
}

