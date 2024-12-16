//dãy a với a[i] là giá cổ phiếu ngày i
//Tìm chuỗi ngày dài nhất cổ phiếu luôn tăng
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0; //2 con tro
    int cnt = 1;
    int res = cnt;
    while(r < n-1){
        r++;

        if(a[r] > a[r-1]) cnt++;
        else{
            res = max(cnt, res);
            cnt = 1;
            l = r;
        }
    }
    res = max(cnt, res);
    cout << res;
    return 0;
}
