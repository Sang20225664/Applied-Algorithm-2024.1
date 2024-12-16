/*Dãy A gồm n phần tử , dãy con ko cần liên tục
Tìm độ dài dãy con chẵn lẻ (tca ptu là số chẵn hoặc lẻ) tăng (không giảm) dài nhất của A*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n;
int a[N];
int dp[N][2]; //0 la chan, 1 la le
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        dp[i][0] = dp[i][1] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <i; j++){
            if(a[i] % 2 == 0 && a[j] % 2 == 0){
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
            if(a[i] % 2 == 1 && a[i] % 2 == 1){
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max({res, dp[i][0], dp[i][1]});
    }
    cout << res;
}
