//Tinh so luong cap so bang nhau
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    long long a[100000];
    unordered_map<long long, long long> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    long long res = 0;
    for(auto it : mp){
        long long x = it.second;
        res += x*(x-1)/2;
    }
    cout << res;
}
