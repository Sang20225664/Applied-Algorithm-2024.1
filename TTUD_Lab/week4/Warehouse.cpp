/* xe tải đến 1 số trạm trong số N trạm trên đg thẳng
a[i] -> số lượng hàng hóa
t[i] -> tgian lấy hàng
lộ trình xe tải là chuỗi x1 < x2 < ... < xk
Khonarg cách giữa hai trạm ltiep mà xe tải đến x[i] và x[i+1] <= D
tổng tgian lấy hàng <= T
=> Tìm lộ trình sao cho tổng hàng lấy đc lớn nhất
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 2;

int n, T, d, a[MAX], t[MAX];
int f[MAX][MAX], res;

void solve(){
    memset(f, 0, sizeof(f));
    res = 0;

    for(int i = 1; i <= n; i++){
        for(int k = t[i]; k<= T; k++){ //duyet theo tgian co the su dung
            for(int j = max(0, i-d); j <= i-1; j++){ //duyet cac nha kho
                f[i][k] = max(f[i][k], f[j][k-t[i]] + a[i]);
            }
            res = max(f[i][k], res);
        }
    }
    cout << res;
}

int main(){
    cin >> n >> T >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> t[i];
    solve();
}
