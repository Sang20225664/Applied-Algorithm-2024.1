#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100; // Số lượng điểm giao hàng tối đa
const int MAXK = 10;  // Số xe tải tối đa

int N, K, Q;                // Số điểm giao hàng, số xe tải, tải trọng mỗi xe
int d[MAXN + 1];            // Số lượng hàng tại mỗi điểm giao hàng
int c[MAXN + 1][MAXN + 1];  // Khoảng cách giữa các điểm
int y[MAXK + 1];            // Điểm giao đầu tiên của mỗi xe
int x[MAXN + 1];            // Điểm tiếp theo của mỗi điểm giao hàng
bool visited[MAXN + 1];     // Đánh dấu các điểm đã được thăm
int load[MAXK + 1];         // Tổng tải hàng của mỗi xe
int f = 0, f_best = INT_MAX; // Chi phí hiện tại và tốt nhất
int segments = 0;           // Số chặng đã được xây dựng
int nbR = 0;                // Số xe thực tế được sử dụng
int Cmin = INT_MAX;         // Chi phí nhỏ nhất giữa hai điểm bất kỳ

// Hàm cập nhật phương án tốt nhất
void updateBest() {
    if (f < f_best) {
        f_best = f;
        // In lộ trình
        cout << "Lo trinh toi uu: " << endl;
        for (int k = 1; k <= K; k++) {
            if (y[k] == 0) continue; // Xe không được sử dụng
            cout << "Xe " << k << ": 0 ";
            int u = y[k];
            while (u > 0) {
                cout << "-> " << u << " ";
                u = x[u];
            }
            cout << "-> 0" << endl;
        }
    }
}

// Kiểm tra tính hợp lệ khi gán giá trị cho x[s]
bool checkX(int v, int k) {
    if (v > 0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

// Thử giá trị cho x[s]
void TRY_X(int s, int k) {
    if (s == 0) {
        if (k < K) TRY_X(y[k + 1], k + 1);
        else if (segments == N + nbR) updateBest();
        return;
    }
    for (int v = 0; v <= N; v++) {
        if (checkX(v, k)) {
            x[s] = v;
            visited[v] = true;
            f += c[s][v];
            load[k] += d[v];
            segments++;

            if (v > 0) {
                if (f + (N + nbR - segments) * Cmin < f_best) {
                    TRY_X(v, k);
                }
            } else {
                if (f + (N + nbR - segments) * Cmin < f_best) {
                    TRY_X(y[k + 1], k + 1);
                }
            }

            // Khôi phục trạng thái
            visited[v] = false;
            f -= c[s][v];
            load[k] -= d[v];
            segments--;
        }
    }
}

// Kiểm tra tính hợp lệ khi gán giá trị cho y[k]
bool checkY(int v, int k) {
    if (v == 0) return true;
    if (load[k] + d[v] > Q) return false;
    if (visited[v]) return false;
    return true;
}

// Thử giá trị cho y[k]
void TRY_Y(int k) {
    int start = (y[k - 1] > 0) ? y[k - 1] + 1 : 0;
    for (int v = start; v <= N; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0) segments++;
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];

            if (k < K) {
                TRY_Y(k + 1);
            } else {
                nbR = segments;
                TRY_X(y[1], 1);
            }

            // Khôi phục trạng thái
            load[k] -= d[v];
            visited[v] = false;
            f -= c[0][v];
            if (v > 0) segments--;
        }
    }
}

// Giải bài toán
void solve() {
    f = 0;
    f_best = INT_MAX;
    y[0] = 0;
    fill(visited, visited + MAXN + 1, false);

    // Tìm khoảng cách nhỏ nhất
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i != j) {
                Cmin = min(Cmin, c[i][j]);
            }
        }
    }

    TRY_Y(1);
    cout << "Chi phi toi thieu: " << f_best << endl;
}

int main() {
    // Nhập dữ liệu
    cin >> N >> K >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cin >> c[i][j];
        }
    }

    solve();
    return 0;
}
