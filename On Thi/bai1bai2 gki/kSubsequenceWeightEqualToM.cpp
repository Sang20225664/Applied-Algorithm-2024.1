//Tinh so luong day con k ptu ltiep cua day a sao cho trong so (tong tca cac ptu) moi day deu bang m
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, m;
    cin >> n >> k >> m;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int q = 0;
    int sum = 0, cnt = 0;
    for(int i = 0; i < k; i++) sum += a[i];
    for(int i = k; i < n; i++){
        if(sum == m) cnt ++;
        sum = sum + a[i] - a[i-k];
    }
    cout << cnt;
}
