#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int ar[MAXN][MAXN], s[MAXN][MAXN];

int main (){
    int n, m, q;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ar[i][j];
            s[i][j] = ar[i][j] + s[i][j-1] + s[i-1][j] - s[i-1][j-1];
        }
    }
    cin >> q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //tổng hcn từ (a,b) đến (c,d)
        int res = s[c][d] - s[c][b-1] - s[a-1][d] + s[a-1][b-1];
        cout << res << endl;
    }
}
