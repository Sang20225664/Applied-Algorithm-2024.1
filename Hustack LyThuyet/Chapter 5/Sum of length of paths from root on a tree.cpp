
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
vector<pair<int, int>> a[MAX]; // Danh sách kề
int d[MAX]; // Tổng độ dài đường đi từ các đỉnh con cháu
int N[MAX]; // Số đỉnh con cháu
int f[MAX]; // Tổng độ dài đường đi từ mọi đỉnh
int p[MAX]; // Cha của một đỉnh
int n;      // Số đỉnh

void DFS1(int u) { // Tính d[u] và N[u] cho mọi đỉnh u
    for (auto [v, w] : a[u]) {
        if (v == p[u]) continue; // Bỏ qua đỉnh cha
        p[v] = u;
        DFS1(v);

        d[u] += d[v] + N[v] * w; // Cập nhật d[u] từ con
        N[u] += N[v];            // Cập nhật N[u]
    }
}

void DFS2(int u) { // Tính f[v] từ f[u]
    for (auto [v, w] : a[u]) {
        if (v == p[u]) continue;
        int F = f[u] - (d[v] + w * N[v]); // Giá trị trung gian
        f[v] = F + d[v] + w * (n - N[v]); // Cập nhật f[v]
        DFS2(v);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Cạnh (u, v) trọng số w
        a[u].push_back({v, w});
        a[v].push_back({u, w}); // Đồ thị vô hướng
    }

    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        d[i] = 0; // Khởi tạo d[i]
        N[i] = 1; // Ban đầu mỗi đỉnh là một cây riêng lẻ
        p[i] = 0;
    }

    p[1] = 1;  // Đặt gốc là đỉnh 1
    DFS1(1);   // Tính d[u] và N[u]
    f[1] = d[1]; // Tổng đường đi tại gốc
    DFS2(1);   // Tính f[u] cho toàn bộ đỉnh
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[i]);
    }
    cout << res;

    return 0;
}
