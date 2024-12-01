#include <bits/stdc++.h>
using namespace std;
int main (){
    int n, q; cin >> n >> q;
    int a[100000];
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n-1;

    int cnt = 0;
    sort(a, a+n);
    while(l < r){
        if(a[l] + a[r] == q) {
            cnt++;
            r--;
            l++;
        }
        else if(a[l] + a[r] > q){
            r--;
        }
        else l++;
    }
    cout << cnt;
    return 0;
}
