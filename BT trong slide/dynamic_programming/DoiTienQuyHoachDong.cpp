#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int D[11];
int imem[11][10001];

int minCoin(int i, int x){
    if(x < 0) return INF;
    if(x == 0) return 0;
    if(i == 0) return INF;

    if(imem[i][x] != -1) return imem[i][x];
    int res = INF;
    res = min(res, 1 + minCoin(i, x-D[i]));
    res = min(res, minCoin(i-1, x));
    imem[i][x] = res;
    return res;
}

void trace(int i, int x){
    if(x == 0) return;
    if(i == 0) return;

    if(x >= D[i] && imem[i][x] == 1 + imem[i][x-D[i]]){
        cout << D[i] << " ";
        trace(i, x-D[i]);
    }
    else trace(i-1, x);
}

int main (){
    memset(imem, -1, sizeof(imem));
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> D[i];
    int res = minCoin(n, x);
    if(res >= INF) cout << -1 << endl;
    else{
        cout << res << endl;
        trace(n, x);
    }
    return 0;

}
