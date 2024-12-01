#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int k; //so luong places ~ suc chua cua bus
int a[2*MAX + 1][2*MAX +1]; //chi phi giua cac diem
int x[MAX]; //lo trinh hien tai
int visited[MAX]; //cac diem da di qua
int load; //so luong hanh khach hien tai
int f; //chi phi cua lo trinh hien tai
int f_best; //chi phi cua lo trinh tot nhat
int x_best[MAX]; //luu lo trinh tot nhat
int Cmin; //chi phi toi thieu giua 2 diem

//ktra xem co the chon diem v vao vi tri k
int check (int v, int k){
    if(visited[v] == 1) return 0; //v da duoc chon
    if(v > n){
        if(!visited[v-n]) return 0; //chua don tra khach nhung da den diem tra
    }
    else if(load >= k) return 0; //qua suc chua cua xe
    return 1;
}

void solution(){ //cap nhat lo trinh tot nhat
    if(f + a[x[2*n]][0] < f_best){
        f_best = f + a[x[2*n]][0]; //cap nhat chi phi tot nhat
        for(int i = 0; i <= 2*n; i++) x_best[i] = x[i]; //cap nhat lo trinh tot nhat
    }
}
void TRY(int k){
    for(int v = 1; v <= 2*n; v++){
        if(check(v, k)){
            x[k] = v;
            f += a[x[k-1]][x[k]]; //cap nhat chi phi
            if(v <= n) load += 1; else load -= 1; // so luong hanh khach
            visited[v] = 1; //danh dau diem v da di qua

            if(k == 2*n) solution(); //neu du lo trinh thi cap nhat
            else if(f + (2*n + 1 -k)*Cmin < f_best) TRY(k+1);
            //neu chi phi uoc luong tot hon chi phi tot nhat thi ktra diem tiep theo
            if(v <= n) load -= 1; else load += 1; //tra khach
            visited[v] = 0;
            f -= a[x[k-1]][x[k]];
        }
    }
}
int main (){
    cin >> n >> k;
    Cmin = 1e7;
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j < 2*n; j++){
            cin >> a[i][j];
            if(i != j && Cmin > a[i][j]) Cmin = a[i][j]; //chi phi nho nhat trong 2 diem bat ki
        }
    }
    load = 0;
    f = 0;
    f_best = 1e9;
    for(int i = 1; i<= 2*n; i++) visited[i] = 0;
    x[0] = 0; //diem bat dau
    TRY(1);
    cout << f_best;
    return 0;
}
