#include <bits/stdc++.h>
using namespace std;

int a[1001], imem[1001];

int LIS(int i){
    if(imem[i] != -1) return imem[i];
    int res = 1;
    for(int j = 1; j < i; j++){
        if(a[j] < a[i]){
            res = max(res, LIS(j) + 1);
        }
    }
    imem[i] = res;
    return res;
}

void trace(int i){
    for(int j = i-1; j >= 1; j--){
        if(a[j] < a[i] && imem[i] == imem[j] + 1){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    int n; cin >> n;
    for(int i = 1; i<= n; i++) cin >> a[i];
    int ans = 0, pos = 0;
    memset(imem, -1, sizeof(imem));
    for(int i = 1; i <= n; i++){
        int cur = LIS(i);
        if(cur > ans){
            ans = cur;
            pos = i;
        }
    }
    cout << "do dai: " << ans << endl;
    cout << "day con tang dai nhat la: ";
    trace(pos);
}
