#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int n, M;
int a[MAX];
int t[MAX]; //prefix sum t[k] = a[1] +... + a[k] (tat ca cac nghiem deu >= 1)
int X[MAX]; //solutions
int f; //sum hien tai
int cnt;

void TRY(int k){
    for(int v = 1; v <= (M-f-(t[n] -t[k]))/a[k]; v++){ //v bdau = 1 vi nghiem phai duong
        X[k] = v;
        f += X[k] * a[k]; //cap nhat tong
        if(k == n){
            if(f == M) cnt++; //neu duyet du he so thi ktra xem tong co dung bang chua
        }
        else TRY(k+1); //de quy: net chua den bien cuoi cung thi thu tiep gia tri cho bien tiep theo
        f-= a[k] *X[k]; //quay lui: sau khi thu thi tru bot gia tri da cong truoc do de quay lai trang thai truoc khi thu
    }
    //(t[n] -t[k]) gioi han chan tren
}

int main (){
    cin >> n >> M;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f = 0;
    t[1] = a[1];
    for(int i = 2; i <= n; i++) t[i] = t[i-1] + a[i];
    cnt = 0;
    TRY(1);
    cout << cnt;
}
