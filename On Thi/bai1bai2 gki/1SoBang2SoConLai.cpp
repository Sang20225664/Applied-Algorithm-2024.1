#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n; int a[2001];
int cnt = 0;

int main (){
    cin >> n;
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(mp.count(a[i] + a[j])){
                cnt++;
                cout << a[i] << " " << a[j] << endl;
               }
        }
    }
    cout << cnt % mod;
}

