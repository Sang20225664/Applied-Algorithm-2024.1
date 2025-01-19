/*(CKI2023.1)
Các khối đá kích thước Li x Wi x Hi (i từ 1 đến n)
Có thể cắt khối đá theo 3 chiều thành 2 khối nhỏ hơn với kích thước nguyên
Các khối có thể xoay theo hướng khác nhau để phù hợp lúc xây pháo đài
1 khối lãng phí nếu không là kích thước mong muốn sau khi cắt
-->Làm thế nào để cắt sao cho số khối lãng phí ít nhất (in ra tổng thể tích tối thiểu của khối đá bị lãng phí)*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_L = 50, MAX_W = 50, MAX_H = 50;
const int INF = 1e9;

// Kích thước mong muốn
int L, W, H;
int n; // Số lượng khối mong muốn
int l[100], w[100], h[100]; // Kích thước từng khối mong muốn

// Bảng DP lưu thể tích lãng phí tối thiểu
int dp[MAX_L + 1][MAX_W + 1][MAX_H + 1];

int main() {
    int t; // Số lượng bộ test
    cin >> t;
    while (t--) {
        cin >> L >> W >> H;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> w[i] >> h[i];
        }

        // Khởi tạo bảng DP
        for (int i = 0; i <= L; i++) {
            for (int j = 0; j <= W; j++) {
                for (int k = 0; k <= H; k++) {
                    dp[i][j][k] = INF; // Mặc định là vô hạn
                }
            }
        }

        // Trạng thái cơ bản: Nếu khối đã có kích thước mong muốn
        for (int i = 0; i < n; i++) {
            dp[l[i]][w[i]][h[i]] = 0;
            dp[l[i]][h[i]][w[i]] = 0; // Xoay khối
            dp[w[i]][l[i]][h[i]] = 0; // Xoay khối
            dp[w[i]][h[i]][l[i]] = 0; // Xoay khối
            dp[h[i]][l[i]][w[i]] = 0; // Xoay khối
            dp[h[i]][w[i]][l[i]] = 0; // Xoay khối
        }

        // Tính bảng DP
        for (int x = 1; x <= L; x++) {
            for (int y = 1; y <= W; y++) {
                for (int z = 1; z <= H; z++) {
                    // Thử cắt theo chiều dài
                    for (int cut = 1; cut < x; cut++) {
                        dp[x][y][z] = min(dp[x][y][z], dp[cut][y][z] + dp[x - cut][y][z]);
                    }
                    // Thử cắt theo chiều rộng
                    for (int cut = 1; cut < y; cut++) {
                        dp[x][y][z] = min(dp[x][y][z], dp[x][cut][z] + dp[x][y - cut][z]);
                    }
                    // Thử cắt theo chiều cao
                    for (int cut = 1; cut < z; cut++) {
                        dp[x][y][z] = min(dp[x][y][z], dp[x][y][cut] + dp[x][y][z - cut]);
                    }

                    // Nếu không cắt được thành khối mong muốn
                    dp[x][y][z] = min(dp[x][y][z], x * y * z);
                }
            }
        }

        // Kết quả là thể tích lãng phí tối thiểu cho khối ban đầu
        cout << dp[L][W][H] << endl;
    }
    return 0;
}
