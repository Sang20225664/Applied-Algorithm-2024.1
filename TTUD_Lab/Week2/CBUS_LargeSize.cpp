#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
int cap;
int a[2*MAX+1][2*MAX+1];
int x[MAX];
int appear[MAX];
int load;
int f;
int f_best;
int x_best[MAX];
int cmin;

void input(){
    cin >> n >> cap;
    cmin = 1e9;
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++) {
            cin >> a[i][j];
            if(i != j && cmin > a[i][j]) cmin = a[i][j];
        }
    }
}

int check(int v, int k){
    if(appear[v] == 1) return 0;
    if( v > n){
        if(!appear[v-n]) return 0;
    }
    else{
        if(load + 1 > cap) return 0;
    }
    return 1;
}

void solution(){ //cap nhat lo trinh tot nhat
    if(f + a[x[2*n]][0] < f_best){
        f_best = f + a[x[2*n]][0]; //cap nhat chi phi tot nhat
        for(int i = 0; i <= 2*n; i++) x_best[i] = x[i]; //cap nhat lo trinh tot nhat
    }
}

void Try(int k){
    for(int v = 1; v <= 2*n; v++){
        if(check(v, k)){
            x[k] = v;
            f += a[x[k-1]][x[k]];
            if(v <= n) load++; else load--;
            appear[v] = 1;
            if(k == 2*n) solution();
            else{
                if(f + (2*n-k+1)*cmin < f_best) Try(k+1);
            }
            if(v <= n) load--; else load++;
            appear[v] = 0;
            f -= a[x[k-1]][x[k]];
        }
    }
}

void solve(){
    load = 0;
    f = 0; f_best = 1000000;
    for(int i = 1; i<= 2*n; i++) appear[i] = 0;
    x[0] = 0;
    Try(1);
    //cout << f_best << endl;
}

void print(){
    for(int i = 0; i <= 2*n; i++) cout << x_best[i] << ' ';
}

int main (){
    input();
    solve();
    print();
    return 0;
}
