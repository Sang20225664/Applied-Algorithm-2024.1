//Cho dãy a1, a2, ..., an. Thực hiện Q truy vấn, mỗi truy vấn đặc trưng bởi cặp chỉ số (i, j) trong đó cần tình tổng ai + a(i+1) + ... aj
//Sd mảng cộng dồn
#include <bits/stdc++.h>
using namespace std;

int main (){
    int n, q;
    cin >> n;
    int a[n+1];
    int p[n+1];
    p[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = a[i] + p[i-1];
    }

    cin >> q;
    while(q--){
        int i, j; cin >> i >> j;
        int sum = p[j] - p[i-1];
        cout << sum << endl;
    }
}
