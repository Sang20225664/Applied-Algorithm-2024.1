/*n nhiệm vụ
nvu i có thời lượng d[i] cần hoàn thành
với mỗi j, j trong Q, j ko thể bdau trc khi i hoàn thành
--> tính tgian hoàn thành sớm nhất
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

// Cấu trúc Arc đại diện cho một cạnh có hướng với trọng số
struct Arc {
    int v; // đỉnh đích
    int w; // trọng số cạnh (ở đây là thời gian thực hiện công việc tại đỉnh nguồn)
    Arc(int _v, int _w) : v(_v), w(_w) {}
};

int n, m;                  // n: số lượng công việc, m: số ràng buộc
int duration[N];           // duration[i]: thời gian thực hiện công việc i
vector<Arc> A[N];          // A[u]: danh sách các cạnh xuất phát từ đỉnh u
int d[N];                  // d[v]: bậc vào của đỉnh v
vector<int> L;             // L: danh sách các đỉnh theo thứ tự topo
int F[N];                  // F[v]: thời gian sớm nhất mà công việc v có thể bắt đầu
int ans;                   // ans: kết quả - thời gian hoàn thành sớm nhất của dự án

void input() {
    memset(d, 0, sizeof d); // Đặt tất cả bậc vào bằng 0 ban đầu
    cin >> n >> m;          // Đọc số lượng công việc và ràng buộc

    // Đọc thời gian thực hiện cho từng công việc
    for (int i = 1; i <= n; i++) {
        cin >> duration[i];
    }

    // Đọc các ràng buộc giữa các công việc
    for (int k = 1; k <= m; k++) {
        int u, v;
        cin >> u >> v;              // Công việc v phụ thuộc vào u
        A[u].push_back(Arc(v, duration[u])); // Tạo cạnh có hướng từ u -> v
        d[v]++;                     // Tăng bậc vào của đỉnh v
    }
}

void topoSort() {
    queue<int> Q; // Hàng đợi để lưu các đỉnh có bậc vào bằng 0

    // Đưa các đỉnh có bậc vào bằng 0 vào hàng đợi
    for (int v = 1; v <= n; v++) {
        if (d[v] == 0) Q.push(v);
    }

    // Thực hiện thuật toán sắp xếp topo
    while (!Q.empty()) {
        int x = Q.front(); Q.pop(); // Lấy đỉnh đầu tiên ra khỏi hàng đợi
        L.push_back(x);             // Đưa đỉnh này vào danh sách topo

        // Duyệt các đỉnh kề với x
        for (int i = 0; i < A[x].size(); i++) {
            int y = A[x][i].v; // Đỉnh kề
            d[y]--;            // Giảm bậc vào của đỉnh kề
            if (d[y] == 0) {   // Nếu bậc vào của y bằng 0, thêm vào hàng đợi
                Q.push(y);
            }
        }
    }
}

void solve() {
    memset(F, 0, sizeof F); // Đặt thời gian bắt đầu sớm nhất của mọi công việc là 0
    ans = 0;                // Khởi tạo giá trị kết quả ban đầu

    // Duyệt qua các đỉnh theo thứ tự topo
    for (int i = 0; i < L.size(); i++) {
        int u = L[i];
        // Cập nhật thời gian hoàn thành dự án
        ans = max(ans, F[u] + duration[u]);

        // Duyệt các cạnh xuất phát từ u
        for (int j = 0; j < A[u].size(); j++) {
            int v = A[u][j].v; // Đỉnh kề
            int w = A[u][j].w; // Trọng số của cạnh

            // Cập nhật thời gian bắt đầu sớm nhất của v
            F[v] = max(F[v], F[u] + w);
        }
    }

    cout << ans << endl;
}

int main() {
    input();      // Nhập dữ liệu đầu vào
    topoSort();   // Thực hiện sắp xếp topo
    solve();      // Giải bài toán chính
    return 0;
}

