//Dem so day con tang
#include<bits/stdc++.h>
using namespace std;

const int N = 20;

int main(){
    int n; cin >> n;
    int a[N];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int i = 1, j = 1;
    int cnt = 0;
    while( j <= n){
        cout << a[j] << ' ';
        j++;


        if(a[j] < a[j-1]){
            cnt++;
            i = j;
            cout << endl;
        }
    }
    cout << endl << cnt;
}
