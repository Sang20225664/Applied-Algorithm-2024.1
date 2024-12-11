/*Dãy n số nguyên a[n].
Trọng số dãy con: tổng các phần tử
dãy con chẵn: trọng số là chẵn
-> Tìm dãy con chẵn của dãy con có trọng số lớn nhất
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
int main (){
    int n; cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long cursum = 0;
    long long maxeven = -INF;
    long long minodd = INF;

    for(int i = 0; i < n; i++){
        cursum += a[i];
        if(cursum % 2 == 0) maxeven = max(cursum, maxeven);
        else {
            if(minodd != INF) maxeven = max(maxeven, cursum - minodd);
            minodd = min(minodd, cursum);
        }
        if(cursum < 0){
            cursum =0;
            minodd = INF;
        }
    }
    if(maxeven == -INF) cout << "NOT_FOUND";
    else cout << maxeven;
    return 0;
}

