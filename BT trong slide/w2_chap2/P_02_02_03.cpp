//Dãy a1, a2,..., an sắp xếp tăng dần (đôi 1 khác nhau). Đếm cặp a[i] + a[j] sao cho a[i] + a[j] = q
//kĩ thuật 2 con trỏ
#include <bits/stdc++.h>
using namespace std;
int main (){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0, l = 0, r = n-1;
    int q; cin >> q;
    while(l < r){
        if(a[l] + a[r] == q){
            res ++;
            l++;
            r--;
        }
        else if(a[l] + a[r] < q) l++;
        else r--;
    }
    cout << res;
    return 0;
}
