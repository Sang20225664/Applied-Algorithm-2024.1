/*n công việc
việc i thời lượng d[i]
nếu cv i bdau tại thời điểm t thì kthuc tại t + d[i]
tại bki thời điểm nào nhiêù nhất 1 cv có thể thực hiện
-> Tìm lịch trình (thời điểm bdau) để thực hiện tca n cv sao cho
    tgian hoàn thành T là nhỏ nhất(thời điểm bdau la 0)
    output: T (thời gian hthanh cviec cuối)*/

#include <bits/stdc++.h>
using namespace std;
int main (){
    int n; cin >> n;

    vector<int>d(n);
    for(int i = 0; i < n; i++) cin >> d[i];

    //sap xep giam dan de uu tien cong viec dai nhat truoc
    sort(d.rbegin(), d.rend());

    int T = 0;
    for(int i = 0; i < n; i++) T = max(T, d[i] + i);

    cout << T << endl;
    return 0;
}
