#include <bits/stdc++.h>
using namespace std;
#define maxn 1000009

int const mod = 1e9 + 7;
int n, a[maxn];
int tmp[maxn];

//hop nhat 2 mang va tra ve so luong cap nghich dao khi hop nhat
int _merge(int l, int m, int r){
    int i = l, j = m + 1, k = l, cnt = 0;
    while(i <= m && j <= r){
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            cnt = ( cnt + (m - i + 1)) %mod;
        }
    }
    //copy phan con lai cua nua trai (neu con) vao mang trung gian
    while( i<= m) tmp[k++] = a[i++];
    //... nua phai
    while(j <= r) tmp[k++] = a[j++];
    //copy phan da duoc hop nhat vao mang goc
    for(i = l; i <= r; i++) a[i] = tmp[i];
    return cnt;
}

int mergeSort(int l, int r){
    int m, cnt = 0;
    if(r > l){
        m = (r + l) /2;
        //de quy cnt: tong cua phan trai, phan phai va so de quy trong merge
        cnt = (cnt + mergeSort(l, m)) %mod;
        cnt = (cnt + mergeSort(m+1, r)) % mod;
        cnt = (cnt + _merge(l, m, r)) % mod;
    }
    return cnt;
}

int main (){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << mergeSort(1, n);
    return 0;
}
