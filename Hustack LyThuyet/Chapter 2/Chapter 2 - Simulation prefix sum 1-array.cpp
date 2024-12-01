#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
int f[1000000];

int main (){
    int q;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 0;
    for(int i = 1; i <= n; i++) f[i] = f[i-1] + a[i];
    cin >> q;
    while(q--){
        int i, j; cin >> i >> j;
        cout << f[j] - f[i-1] << endl;

    }
    return 0;
}
