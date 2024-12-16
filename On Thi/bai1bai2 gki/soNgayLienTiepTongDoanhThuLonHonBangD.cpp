/*doanh thu ngay i là a[i]
Tính số dãy con gồm các ngày ltiep tổng doanh thu lon hon bang D"
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int d; cin >> d;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<long long> p(n+1, 0);
    for(int i = 1; i <=n; i++) p[i] = p[i-1] + a[i-1];
    int cnt = 0;
    int l = 0;
    for(int r = 0; r <n; r++){
        while(l <= r && p[r+1] - p[l] >= d){
            cnt+= (n-r);
            l++;
        }
    }
    cout << cnt;
    return 0;
}
