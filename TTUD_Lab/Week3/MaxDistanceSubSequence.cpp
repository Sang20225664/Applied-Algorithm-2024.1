#include <bits/stdc++.h>
using namespace std;
#define maxn 100005

int t, n, c, a[maxn];

bool check(int d){
    int cnt = 1;
    int i = 1, j = 2;
    while(i < n){
        while(j <= n && a[j] - a[i] < d) j++;
        if( j <= n) cnt++;
        if( cnt >= c) return true; //lay du c phan tu
        i = j;
        j++;
    }
    return false;
}

int maxDis(){
    int l = 0, r = a[n] - a[1];
    while(l <= r){
        int m = (l+ r)/2;
        if(check(m)) l = m + 1; //thu ket qua o nua phai
        else r = m -1; //thu ket qua o nua trai
    }
    return r;
}
int main (){
    cin >> t;
    while(t--){
        cin >> n >> c;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a+n + 1);
        cout << maxDis() << endl;
    }
}
