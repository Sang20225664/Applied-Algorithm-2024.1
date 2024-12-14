/*n nhà kho trên 1 mặt phẳng
nhà kho i co kl vàng là a[i]
-> Chọn nhà kho sao cho
    tổng lượng vàng lớn nhất
    2 nhà kho ltiep có kc nằm trong khoảng [L1, L2]*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1; // Kích thước tối đa của mảng
int a[N], S[N]; // `a` chứa mảng đầu vào, `S` chứa tổng lớn nhất tại mỗi vị trí
int n, L1, L2, ans; // `n`: số phần tử, `L1`, `L2`: giới hạn khoảng cách, `ans`: kết quả

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L1 >> L2; // Nhập số phần tử và khoảng cách L1, L2
    for (int i = 1; i <= n; i++) cin >> a[i]; // Nhập các phần tử
}

void solve() {
    deque<int> d; // Deque để lưu chỉ số các phần tử ứng viên cho bài toán con
    ans = 0; // Giá trị lớn nhất ban đầu là 0

    // Duyệt qua tất cả các phần tử từ 1 đến n
    for (int i = 1; i <= n; i++) {
        // Loại bỏ các chỉ số ra khỏi deque không còn hợp lệ (nằm ngoài phạm vi L2)
        while (!d.empty() && d.front() < i - L2) {
            d.pop_front();
        }

        // Xác định phần tử mới có thể thêm vào deque
        int j = i - L1; // Chỉ số cách `i` đúng L1 chỉ số
        if (j >= 1) {
            // Loại bỏ các phần tử có giá trị S[j] nhỏ hơn S[j'] (chúng không còn tối ưu)
            while (!d.empty() && S[d.back()] < S[j]) {
                d.pop_back();
            }
            // Thêm chỉ số `j` vào deque
            d.push_back(j);
        }

        // Tính S[i]: Giá trị tại `i` cộng với giá trị tốt nhất từ deque
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);

        // Cập nhật kết quả toàn cục
        ans = max(ans, S[i]);
    }

    // In ra kết quả
    cout << ans;
}

int main() {
    input(); // Đọc dữ liệu đầu vào
    solve(); // Tính toán và in kết quả
    return 0;
}

