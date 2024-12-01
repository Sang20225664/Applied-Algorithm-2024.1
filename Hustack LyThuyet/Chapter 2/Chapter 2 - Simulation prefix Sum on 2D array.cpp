#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[2000][2000];
int f[2001][2001];
int main (){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for(int i = 0; i <= n; i++) f[i][0] = 0;
    for(int j = 0; j <= m; j++) f[0][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    }
    int q; cin >> q;
    while(q--){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        cout << f[r2][c2] - f[r2][c1-1] -f[r1-1][c2] + f[r1-1][c1-1] << endl;
    }
}
