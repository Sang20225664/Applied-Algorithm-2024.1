//trong d ngay voi muc tieu hoc sumTime giờ, mỗi ngày có mintime và maxtime
//Ktra xem có thể học đủ số sumTime ko?
#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, sum;
    cin >> d >> sum;
    vector<int>mint(d), maxt(d), res(d);

    int summin = 0, summax = 0;
    for(int i = 0; i < d; i++){
        cin >> mint[i] >> maxt[i];
        summin += mint[i];
        summax += maxt[i];
        res[i] = mint[i];
    }
    if(sum < summin || sum > summax){
        cout << "NO";
        return 0;
    }
    int remain = sum - summin;
    for(int i = 0; i < d; i++){
        int extra = min(maxt[i] - mint[i], remain);
        res[i] += extra;
        remain -= extra;
    }
    cout << "YES" << endl;
    for(int i = 0; i < d; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
