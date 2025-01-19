/*mỗi đồn đều lắp sóng vô tuyến nhưng chỉ có 1 số đc lắp kênh vệ tinh
2 đồn có thể liên lạc nếu cả 2 đều đc đặt kênh vệ tinh
2 đồn chỉ liên lạc qua vô tuyến nếu khoàng cách <= D
Kc tính theo: (A.x - B.x)^2 + (A.y - B.y)^2 trong đó A.x, B.x là hoành độ đồn A, B, tương tự với y là tung độ
--> Xác định giá trị D tối thiểu sao cho tất cả đồn biên phòng có thể liên lạc 2 chiều với nhau
~ mỗi cawoh phải có ít nhất 1 đg truyền trực tiếp hoặc gián tiếp qua 1/1 số đồn trung gian
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int n1, n2, L, M, P;
int a[MAX];
vector<pair<int, int>> restrictions;

int dp[MAX][MAX][MAX];

int main() {
    // Input
    cin >> n1 >> n2;
    for (int i = 1; i <= n1 + n2; i++) cin >> a[i];
    cin >> L >> M >> P;

    // Read restrictions
    restrictions.resize(P);
    for (int i = 0; i < P; i++) {
        cin >> restrictions[i].first >> restrictions[i].second;
    }

    // Initialize DP
    memset(dp, -1, sizeof(dp)); // -1 means not calculated
    dp[0][0][0] = 0;

    // DP transition
    for (int i = 1; i <= n1 + n2; i++) {
        for (int j = 0; j <= n1; j++) {
            for (int k = 0; k <= n2; k++) {
                if (dp[i-1][j][k] == -1) continue;

                // Case 1: Do not select stock i
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);

                // Case 2: Select stock i
                if (i <= n1 && j + 1 <= n1) {
                    dp[i][j+1][k] = max(dp[i][j+1][k], dp[i-1][j][k] + a[i]);
                }
                if (i > n1 && k + 1 <= n2) {
                    dp[i][j][k+1] = max(dp[i][j][k+1], dp[i-1][j][k] + a[i]);
                }
            }
        }
    }

    // Find result
    int max_profit = -1;
    for (int j = M; j <= n1; j++) {
        for (int k = M; k <= n2; k++) {
            if (j + k <= L) {
                max_profit = max(max_profit, dp[n1 + n2][j][k]);
            }
        }
    }

    cout << max_profit << endl;
    return 0;
}
