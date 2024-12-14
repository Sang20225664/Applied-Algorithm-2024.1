#include <bits/stdc++.h>
using namespace std;

int X[7]; // H, U, S, T, O, I, C
int N;
int cnt;
bool visited[10];

// Kiểm tra giá trị có hợp lệ không
bool check(int v, int k) {
    if (k == 0 && v == 0) return false; // H không được bằng 0
    if (k == 2 && v == 0) return false; // S không được bằng 0
    if (visited[v]) return false;       // Không được trùng giá trị
    return true;
}

// Kiểm tra tổng HUST + SOICT == N
void sol() {
    int hust = X[0] * 1000 + X[1] * 100 + X[2] * 10 + X[3];
    int soict = X[2] * 10000 + X[4] * 1000 + X[5] * 100 + X[6] * 10 + X[3];
    if (hust + soict == N) cnt++;
}

// Thử tất cả các tổ hợp
void Try(int k) {
    for (int v = 0; v < 10; v++) {
        if (check(v, k)) {
            X[k] = v;
            visited[v] = true;
            if (k == 6) sol(); // Nếu đã đủ 7 ký tự, kiểm tra tổng
            else Try(k + 1);   // Thử ký tự tiếp theo
            visited[v] = false; // Backtrack
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        memset(visited, false, sizeof(visited));
        cnt = 0;
        if (N % 2 == 1 || N > 200000) {
            cout << 0 << endl; // Không hợp lệ
            continue;
        } else {
            Try(0);           // Bắt đầu thử từ ký tự đầu tiên
            cout << cnt << endl; // In số lượng cách tìm được
        }
    }

    return 0;
}
