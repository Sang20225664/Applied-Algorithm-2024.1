/*N phần tử trên đường thẳng tại các vị trí x1 -> x[n]
khoảng cách tập hợp con N ptu: kc nhỏ nhất giữa 2 ptu
--> tìm tập hợp con của N ptu chứa đúng C ptu sao cho kc là lớn nhất*/

#include <bits/stdc++.h>
using namespace std;

//Kiểm tra có thể chọn C phần tử với khoảng cách tối thiểu là mid?
bool check(vector<int>& pos, int c, int mid){
    int cnt = 1; //ptu dau tien
    int lastpos = pos[0];

    for(int i = 1; i < pos.size(); i++){
        if(pos[i] - lastpos >= mid){
            cnt++;
            lastpos = pos[i];
            if(cnt == c) return true;
        }
    }
    return false;
}

void findMaxDisSub(vector<int> &pos, int n, int c){
    sort(pos.begin(), pos.end());
    int low = 1, high = pos[n-1] - pos[0];
    int res = 0;
    if( n == c){
        cout << high << endl;
        return;
    }
    while(low <= high){
        int mid = low + (high - low)/2;
        if(check(pos, c, mid)){
            res = mid;
            low = mid + 1;
        }
        else high = mid -1;
    }
    cout << res << endl;

}

int main (){
    int t; cin >> t;
    while(t--){
        int n; int c;
        cin >> n >> c;
        vector<int>x(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        findMaxDisSub(x, n, c);
    }
    return 0;
}
