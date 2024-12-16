// Tinh số tập con dãy n số nguyên có tổng trong khoảng A, B
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int a[N];
int n, A, B;
int res = 0;
bool check(int sum){
    if(sum >= A && sum <= B) return true;
    return false;
}

void Try(int k, int sum){
    if(k == n){
        if(check(sum)) res++;
        return;
    }
    Try(k+1, sum); //thu tiep khi khong chon a[k] vao sum
    Try(k + 1, sum + a[k]); //thu tiep voi a[k] them vao sum
}

int main(){
    cin >> n >> A >> B;
    for(int i = 0; i < n; i++) cin >> a[i];

    Try(0, 0);
    cout << res;
}
