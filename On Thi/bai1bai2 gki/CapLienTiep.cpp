//Dem so cap cach nhau 1dv
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[100000];
    unordered_map<int, int> mp; //gtri a[i] va tan suat cua no
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int cnt = 0;
    for( auto& [val, fre] : mp){
        if(mp.count(val+1)){
            cnt += fre*mp[val+1];
        }
    }
    cout << cnt;
}
