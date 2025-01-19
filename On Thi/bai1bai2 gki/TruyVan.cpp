/*2024.1
a[i] là số tiền gửi trong ngày i
Xử lí m truy vấn với i, j
Truy vấn trả về 1 nếu tổng số tiền khách hàng gửi từ ngày i đến j >= X và <= Y
ngược lại in ra 0
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x, y; cin >> n >> x >> y;
    int a[n];
    for(int i = 1; i<= n; i++) cin >> a[i];
    int m; cin >> m;
    int dp[n];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1] + a[i];
    }
    while(m--){
        int i, j; cin >> i >> j;
        if(dp[j] - dp[i-1] >= x && dp[j] - dp[i-1] <= y) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
