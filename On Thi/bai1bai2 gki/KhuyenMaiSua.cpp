/*Mỗi hộp sữa in 1 số tự nhiên từ dsach các số tự nhiên bí mật khác nhau cho trước
Nếu thu thập 1 tập các số khác nhau thì đc quà
    tổng >= năm thành lập
    chia hết cho 5
-> Có bnh cách thu thâpj để đc đổi quà
(2 cách khác nhau nếu tập các số tự nhiên là khác nhau)
*/
#include <bits/stdc++.h>
using namespace std;

int const N = 1e6+1;
int a[N];
int n, year;
int res = 0;

void backtrack(int i, int sum){
    if(sum >= year && sum % 5 == 0){
        res++;
    }
    for(int j = i; j <n ; j++)
        backtrack(j+1, sum + a[j]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin  >> year;
    backtrack(0, 0);
    cout << res;
}
