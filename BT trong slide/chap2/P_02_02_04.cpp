//tìm dãy con dài nhất tổng nhỏ hơn hoặc bằng q
#include <bits/stdc++.h>
using namespace std;
int main (){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0, s = 0, l = 0;
    int q; cin >> q;
    for(int r = 0; r < n; r++){
        s += a[r];
        while(s > q){
            s-= a[l];
            l++;
        }
        res = max(res, r-l + 1);
    }
    cout << res;
}
