#include <bits/stdc++.h>
using namespace std;

int a[1001], imem[1001];
bool bmark[1001];

int maxSum(int i){
    if(i == 1) return a[i];
    if(bmark[i]) return imem[i];
    int res = max(a[i], a[i] + maxSum(i-1));
    imem[i] = res;
    bmark[i] = true;
    return res;
}

void trace(int i){
    if( i != 1 && imem[i] == a[i] + imem[i-1]){
        trace(i-1);
    }
    cout << a[i] << " ";
}

int main(){
    memset(bmark, false, sizeof(bmark));
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int res = -1e9;
    int id;
    for(int i = 1; i <= n; i++){
        int cur = maxSum(i);
        if(cur > res){
            res = cur;
            id = i;
        }
    }
    cout << res << endl;
    trace(id);
}
