/*n số nguyên đôi 1 khác nhau
->đếm số p các bộ 3 chỉ số i, j, k sao cho ai + ạ + ak = q
(kqua mod 1e9 + 7)
*/

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main(){
    int n, q; cin >> n >> q;
    if(n < 3) {
        cout << 0;
        return 0;
    }
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int p = 0;
    int j, k;
    for(int i = 0; i < n-2; i++){
        j = i+1; k = n-1;
        while(j < k){
            int sum = a[i] + a[j] + a[k];
            if(sum == q) {
                p++;
                j++;
                k--;
            }
            else if(sum <  q) j++;
            else k--;
        }
    }
    cout << p % mod;
}
