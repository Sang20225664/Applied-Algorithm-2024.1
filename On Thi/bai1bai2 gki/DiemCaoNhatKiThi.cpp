/*a[i] là điểm của thí sinh thứ i. Tính điểm cao nhất kì thi*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << *max_element(a.begin(), a.end());
}
