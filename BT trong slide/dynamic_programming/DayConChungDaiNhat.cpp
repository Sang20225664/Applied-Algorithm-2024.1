#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
string x, y;
int mem[N][N];

int LCS(int i, int j){
    if(i == 0 || j == 0) return 0;
    if(mem[i][j] != -1) return mem[i][j];
    if(x[i-1] == y[j-1]) return mem[i][j] =  1 + LCS(i-1, j-1);
    return mem[i][j] = max(LCS(i, j-1), LCS(i-1, j));
}

void trace(int i, int j){
    if(i == 0 || j == 0) return;
    if(x[i-1] == y[j-1] ){
        cout << x[i-1];
        trace(i-1, j-1);
        return;
    }
    if(mem[i][j] == mem[i][j-1]){
        trace(i, j-1);
        return;
    }
    trace(i-1, j);
}

int main (){
    cin >> x >> y;
    int n = x.size();
    int m = y.size();
    memset(mem, -1, sizeof(mem));
    cout << LCS(n, m);
    cout << endl;
    trace(n, m);
}
