/*n người chơi có điểm là a[i]
Tìm điểm thấp nhất và cao nhất*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i< n; i++) cin >> a[i];
    cout << *min_element(a.begin(), a.end())<< " " << *max_element(a.begin(), a.end()) ;
}
