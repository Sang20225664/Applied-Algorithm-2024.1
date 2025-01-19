/*n cột mốc cách đều từ 1 -> n
2 cột mốc liên tiếp cách nhau 1 dặm
mỗi cột đều có bùa chú giúp nhảy qua để tới 1 cột mốc khách phía trước
giá trị cột mốc biểu thị số dặn tối đa có thể nhảy
-> tìm cách nhảy từ cột mốc đầu đến cột cuối với số lần nhảy ít nhất
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int n;
int p[MAX];

int bfs_min_jumps() {
    vector<bool> visited(n + 1, false); // Đánh dấu các cột đã thăm
    queue<pair<int, int>> q; // Hàng đợi lưu (vị trí hiện tại, số bước nhảy)

    q.push({1, 0}); // Bắt đầu từ cột 1 với 0 bước nhảy
    visited[1] = true;

    while (!q.empty()) {
        auto [current, jumps] = q.front();
        q.pop();

        // Nếu đạt tới cột cuối, trả về số bước nhảy
        if (current == n) return jumps;

        // Duyệt các cột mốc có thể nhảy đến
        for (int i = 1; i <= p[current]; i++) {
            int next = current + i;
            if (next > n) break; // Không nhảy quá cột cuối
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, jumps + 1});
            }
        }
    }

    return -1; // Không thể đến cột cuối
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> p[i];

        // Tìm số bước nhảy ít nhất
        cout << bfs_min_jumps() << endl;
    }
    return 0;
}
