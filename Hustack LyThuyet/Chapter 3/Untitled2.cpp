#include <bits/stdc++.h>
using namespace std;

int n, cap, c[1000][1000];
int x[1000];
bool visited[1000];
int load = 0, f = 0, f0 = INT_MAX, x0[1000], cmin = INT_MAX;

void input() {
    cin >> n >> cap;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j && cmin > c[i][j]) cmin = c[i][j];
        }
    }
}

bool check(int v, int k) {
    if (visited[v]) return false;
    if (v > n && !visited[v - n]) return false; // v > n thì v là điểm trả khách
    if (load + (v <= n ? 1 : -1) > cap) return false; // kiểm tra tải trọng
    return true;
}

void Try(int k) {
    for (int v = 1; v <= 2 * n; v++) {
        if (check(v, k)) {
            x[k] = v;
            f += c[x[k - 1]][x[k]]; // cập nhật chi phí
            load += (v <= n ? 1 : -1); // cập nhật tải trọng
            visited[v] = true;

            if (k == 2 * n) { // đã chọn tất cả các điểm
                int total_cost = f + c[x[2 * n]][0]; // tính chi phí quay về
                if (total_cost < f0) {
                    f0 = total_cost;
                    copy(x, x + 2 * n + 1, x0); // lưu lại đường đi tốt nhất
                }
            } else if (f + (2 * n - k + 1) * cmin < f0) {
                Try(k + 1); // tiếp tục tìm kiếm
            }

            // hoàn tác
            load -= (v <= n ? 1 : -1);
            visited[v] = false;
            f -= c[x[k - 1]][x[k]]; // cập nhật lại chi phí
        }
    }
}

int main() {
    input();
    x[0] = 0; // bắt đầu từ điểm 0
    Try(1); // bắt đầu thuật toán
    cout << f0 << endl; // in ra chi phí tối ưu
    return 0;
}
