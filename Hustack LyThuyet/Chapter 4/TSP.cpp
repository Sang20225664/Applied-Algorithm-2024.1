/* n tpho
kc từ i đến j là c[i][j]
1 người khởi hành từ tpho 1, ghé thăm hết tpho còn lại đúng 1 lần rồi trở lại 1
Tìm lộ trình sao cho khoảng cách di chuyển ngắn nhất*/

/* n tpho
kc từ i đến j là c[i][j]
1 người khởi hành từ tpho 1, ghé thăm hết tpho còn lại đúng 1 lần rồi trở lại 1
Tìm lộ trình sao cho khoảng cách di chuyển ngắn nhất*/

#include <bits/stdc++.h>
using namespace std;

const int N = 21;       // Giới hạn số thành phố
const int INF = 1e9;    // Giá trị vô cùng lớn để so sánh

int n;                  // Số thành phố
int c[N][N];            // Ma trận khoảng cách giữa các thành phố
int dp[N][1 << N];      // Mảng lưu chi phí tối ưu

void solve() {
    // Khởi tạo mảng dp với giá trị lớn (vô cùng)
    for (int i = 0; i < N; i++) {
        for (int mask = 0; mask < (1 << N); mask++) {
            dp[i][mask] = INF;
        }
    }

    // Khởi tạo trạng thái ban đầu: đi từ thành phố 0 đến mỗi thành phố i
    dp[0][1] = 0;  // Xuất phát từ thành phố 0, trạng thái ban đầu chỉ ghé thăm thành phố 0

    // Quy hoạch động để cập nhật chi phí tối ưu cho các trạng thái
    for (int mask = 1; mask < (1 << n); mask++) {   // Duyệt qua tất cả các tập hợp thành phố
        for (int i = 0; i < n; i++) {              // Thành phố hiện tại
            if (!(mask & (1 << i))) continue;      // Nếu thành phố i không nằm trong mask, bỏ qua
            for (int j = 0; j < n; j++) {          // Thành phố trước đó
                if (i == j || !(mask & (1 << j))) continue;  // Thành phố j không thuộc mask hoặc trùng i
                dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + c[j][i]);
            }
        }
    }

    // Tìm kết quả tối ưu từ tất cả các lộ trình kết thúc tại thành phố i và quay về 0
    int res = INF;
    for (int i = 1; i < n; i++) {
        res = min(res, dp[i][(1 << n) - 1] + c[i][0]);
    }

    cout << res << endl;  // In ra kết quả
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    solve();
    return 0;
}


