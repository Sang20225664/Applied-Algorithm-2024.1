//Dãy a và số k. Tìm đoạn con của a có ít nhất k phần tử và trung bình cộng lớn nhất có thể

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    int a[100000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    double sum = 0;
    double res = 0;
    for(int i = 0; i < k; i++){
        sum += a[i];
    }
    for(int i = k; i < n; i++){
        res = max(res, sum/k);
        if(i < n){
            sum = sum + a[i] - a[i-k];
        }
    }
    printf("%.5lf", res);
}
