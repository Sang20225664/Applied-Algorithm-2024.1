#include <bits/stdc++.h>
using namespace std;

int main (){
    int n; cin >> n;
    int a[100000];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    string cmd;
    int k;
    while(cin >> cmd){
        if(cmd == "#") break;
        cin >> k;
        auto it = upper_bound(a, a + n, k);
        if(it == a+ n) cout << -1 << endl;
        else cout << *it << endl;
    }
    return 0;
}
