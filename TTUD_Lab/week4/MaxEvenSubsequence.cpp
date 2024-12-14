#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n;
long long a[N];
long long s0[N]; //Tong lon nhat cua day con chan kthuc tai i
long long s1[N]; //tong lon nhat cua day con le kthuc tai i
bool b0[N]; //danh dau su ton tai cua day con chan tai chi so i
bool b1[N]; // ... le...

void solve(){
    //TH co so
    if(a[1] % 2 == 0){
        s0[1] = a[1];
        b0[1] = true;
        b1[1] = false;
    }
    else{
        s1[1] = a[1];
        b1[1] = true;
        b0[1] = false;
    }
    for(int i = 2; i <= n; i++){
        if(a[i] % 2 == 0){
            if(b0[i-1]){ //ktra co day con chan trc do chua
                s0[i] = max(s0[i-1], 0LL) + a[i]; //neu day trc do duong thi cong them ptu moi, ko thi day moi bang ptu moi
                b0[i] = true;
            }
            else{ //trc do ch co thi h tao day chan
                s0[i] = a[i];
                b0[i] = true;
            }
            if(b1[i-1]){
                s1[i] = s1[i-1] + a[i]; //cong them ptu chan vao tong le
                b1[i] = true;
            }
            else b1[i] = false; //neu trc do k co day le thi h cung k tao dc vi dang la ptu chan
        }
        else{ //xet ptu le
            if(b1[i-1]){ //neu da co day le
                s0[i] = s1[i-1] + a[i]; //le + le = chan
                b0[i] = true;
            }
            else{
                b0[i] = false; //trc do k co day le thi h ko tao duoc day chan
            }
            if(b0[i-1]){
                s1[i] = max(s0[i-1], 0LL) + a[i]; //chan + le = le
                b1[i] = true;
            }
            else{
                s1[i] = a[i]; //ch co day le thi h lap day le
                b1[i] = true;
            }
        }
    }
    long long ans = -1e18;
    for(int i = 1; i <= n; i++){
        if(b0[i] && ans < s0[i]) ans = s0[i]; //tinh day chan
    }
    if(ans == -1e18) cout << "NOT_FOUND" << endl;
    else cout << ans << endl;
}

int main (){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    solve();
    return 0;
}
