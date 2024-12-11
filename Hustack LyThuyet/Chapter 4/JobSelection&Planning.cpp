/*n công việc
công việc i có thời hạn d[i], lợi nhuận p[i] nếu hoàn thành trc thời hạn
mỗi cv mất một đvi tgian -> thời hạn tối thiểu là 1
*KO thể thực hiện nhiều hơn 1 cv cùng 1 lúc
-> Chọn và lên lịch tập hợp con các công việc của J sao cho tổng lợi nhuận lớn nhất*/

#include <bits/stdc++.h>
using namespace std;

struct job{
    int ddl;
    int val;
};

bool compare(job a, job b){
    return a.val > b.val;
}

int main (){
    int n; cin >> n;
    vector<job> js(n);
    for(int i = 0; i < n; i++){
        cin >> js[i].ddl >> js[i].val;
    }
    sort(js.begin(), js.end(), compare);

    vector<bool> time(n + 1, false); //đánh dấu thời điểm đã sd
    int total = 0;

    for(int i =0; i < n; i++){
        //Tìm thời điểm gần nhất trước ddl
        for(int j = min(n, js[i].ddl); j>= 1; j--){
            if(!time[j]){
                time[j] = true; //thoi diem da dc sd
                total += js[i].val;
                break;
            }
        }
    }
    cout << total << endl;
}
