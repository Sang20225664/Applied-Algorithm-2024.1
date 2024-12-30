/*Đthi có hướng n nút m cung
mỗi cung (u, v) có trọng số không âm w(u, v)
--> Tìm đường đi ngắn nhất từ nút s đến nút t*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5 + 1;
int n, m, s, t;
vector<pair<int, int>> a[N]; // Danh sách kề: (đỉnh kề, trọng số)

int solve(int s, int t) {
    vector<int> dist(n + 1, INF); // Khởi tạo khoảng cách vô cùng
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Hàng đợi ưu tiên (khoảng cách, đỉnh)

    dist[s] = 0;
    pq.push({0, s}); // Đưa đỉnh bắt đầu vào hàng đợi

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // Nếu khoảng cách không tối ưu, bỏ qua

        for (auto [v, w] : a[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return (dist[t] == INF ? -1 : dist[t]); // Trả về -1 nếu không có đường đi
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Nhập cạnh (u, v) với trọng số w
        a[u].push_back({v, w});
    }
    cin >> s >> t;

    cout << solve(s, t);
    return 0;
}
