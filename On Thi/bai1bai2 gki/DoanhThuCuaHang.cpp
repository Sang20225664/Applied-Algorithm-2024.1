/*n ngày liên tiếp doanh thu là a[i]
đếm số lượng các ngày doanh thu đạt >= X và <= Y
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x, y; cin >> n >> x >>y;
    int a[n];
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] >= x && a[i] <= y) cnt++;
    }
    cout << cnt;
}
