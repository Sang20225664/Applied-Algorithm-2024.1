//Tim tap con ko rong cua day x sao cho tong cac phan tu >= ans
#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 1;
int n, ans;
int x[N];
int res;
int const MOD = 1e9 + 7;
vector<int> currentSubset;
void backTrack(int pos, int sum) {
    if (sum >= ans) {
        res = (res + 1) % MOD;

        // In ra tập con hiện tại và tổng của nó
        cout << "Subset: { ";
        for (int val : currentSubset) {
            cout << val << " ";
        }
        cout << "} -> Sum: " << sum << endl;
    }

    for (int i = pos; i < n; i++) {
        currentSubset.push_back(x[i]);        // Thêm phần tử vào tập con
        backTrack(i + 1, sum + x[i]);        // Gọi đệ quy với tổng mới
        currentSubset.pop_back();            // Loại bỏ phần tử sau khi xử lý
    }
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i];
    cin >> ans;
    backTrack(0, 0);
    cout << res;
}

