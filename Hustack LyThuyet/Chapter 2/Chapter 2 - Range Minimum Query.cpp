//phan tu min cua mang
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define LOG  20 //gioi han so mu logarit de luu 2^i chon 20 vi 2^20 ~ 10^6
int st[MAX][LOG]; //mang luu sparse table, st[i][j] -> gtri nho nhat cua doan con tu i co do dai 2^j
int n, m;

void SparseTable(int a[]){
    for(int i = 0; i < n; i++) st[i][0] = a[i]; //doan con dai 2^0
    for(int j = 1; (1<<j) <= n; j++){ //duyet 2^j
        for(int i = 0; i + (1<<j) - 1 < n; i++){ //i + 2^j -1 ko vuot qua mang
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq(int l, int r){
    int j = log2(r-l+1);
    return min(st[l][j], st[r-(1<<j) + 1][j]);
}
int main (){
    cin >> n;
    int a[MAX];
    for(int i = 0; i < n; i++) cin >> a[i];
    SparseTable(a);
    /*for(int j = 1; (1<<j) <= n; j++){
        for(int i = 0; i + (1<<j) -1 < n; i++) cout << st[i][j] << ' ';
        cout << endl;
    }*/
    cin >> m;
    long long q = 0;
    while(m--){
        int i, j;
        cin >> i >> j;
        q += rmq(i, j);
    }
    cout << q;
    return 0;
}
