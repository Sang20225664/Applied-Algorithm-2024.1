/*Lập kế hoạch cho y tá N ngày ltiep
mỗi y tá ko thể làm tca N ngày mà phải có ngày nghỉ ngơi
Khoảng thời gian làm việc của 1 y tá:
- Chuỗi các ngày ltiep mà y tá phải làm việc
- Độ dài khoảng tgian làm việc: số ngày liên tiếp của khoảng tgian làm việc
*Ràng buộc:
    Mỗi y tá chỉ đc nghỉ 1 ngày giữa 2 ca ltiep
    Độ dài mỗi gdoan phải >= K1 và <= K2
Output: tổng số kế hoạch thỏa mãn
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
int N, K1, K2;
int s0[MAX], s1[MAX]; // số cách lập lịch: s0-> ngày i nghỉ, s1 -> ngày i là ngày cuối làm việc
void solve(){
    for(int i = 1; i <= N; i++){
        s0[i] = 0;
        s1[i] = 0;
    }
    s1[K1] = 1;
    s0[1] = 1; //nghỉ ngày đầu tiên cũng là 1 cách
    s0[0] = 1; //trạng thái ban đầu ngày 0 là ngày nghỉ

    for(int i = K1+1; i<= N; i++){
        s0[i] = s1[i-1]; //ngày i nghỉ thì i-1 là ngày cuối làm việc của đợt trc
        s1[i] = 0; //reset cho từng vòng lặp
        for(int j = K1; j<= K2; j++){
            if( i >= j) s1[i] += s0[i-j];
        }
    }
    int res = s0[N] + s1[N];
    cout << res;
}

int main(){
    cin >> N >> K1 >> K2;
    solve();
}

