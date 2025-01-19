/*mã cổ phiếu đánh số từ 1 đến n1 + n2
cổ phiếu công nghệ từ 1 -> n1
cổ phiếu bán lẻ từ n1 + 1 đến n1 + n2
mỗi mã cổ phiếu có mã i sinh lợi nhuận a[i]
Chiến lược đầu tư:
    Ko quá L mã khác nhau
    Mỗi nhóm đầu tư ít nhất M mã khác nhau
    Lập danh sách P cặp không cùng đầu tư u, v: nếu đầu tư u sẽ ko đầu tư v và ngược lại
--> Tìm phương án đầu tư mang lợi nhuận cao nhất
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int n1, n2;         // Số mã cổ phiếu công nghệ và bán lẻ
int a[MAX];         // Lợi nhuận của từng mã cổ phiếu
int l, m, p;        // Tổng số mã tối đa, số mã tối thiểu mỗi nhóm, số cặp ràng buộc
vector<pair<int, int>> P; // Danh sách cặp không thể đầu tư đồng thời
int max_profit = 0; // Lợi nhuận tối đa tìm được
vector<int> best_selection; // Phương án tối ưu
vector<int> selected(MAX, 0); // Mảng đánh dấu các mã cổ phiếu đã chọn

void backtrack(int index, int current_profit, int group1_count, int group2_count, int selected_count) {
    // Nếu đã duyệt hết các mã cổ phiếu
    if (index > n1 + n2) {
        // Kiểm tra ràng buộc
        if (selected_count <= l && group1_count >= m && group2_count >= m) {
            if (current_profit > max_profit) {
                max_profit = current_profit;
                best_selection.clear();
                for (int i = 1; i <= n1 + n2; i++) {
                    if (selected[i]) best_selection.push_back(i);
                }
            }
        }
        return;
    }

    // Không chọn mã cổ phiếu `index`
    backtrack(index + 1, current_profit, group1_count, group2_count, selected_count);

    // Kiểm tra xem có thể chọn mã cổ phiếu `index` không
    bool can_select = true;
    for (auto& pair : P) {
        if ((pair.first == index && selected[pair.second]) ||
            (pair.second == index && selected[pair.first])) {
            can_select = false;
            break;
        }
    }
    if (!can_select) return;

    // Chọn mã cổ phiếu `index`
    selected[index] = 1;
    if (index <= n1) {
        backtrack(index + 1, current_profit + a[index], group1_count + 1, group2_count, selected_count + 1);
    } else {
        backtrack(index + 1, current_profit + a[index], group1_count, group2_count + 1, selected_count + 1);
    }
    selected[index] = 0; // Quay lui
}

int main() {
    cin >> n1 >> n2;
    for (int i = 1; i <= n1 + n2; i++) cin >> a[i];
    cin >> l >> m >> p;
    P.resize(p);
    for (int i = 0; i < p; i++) {
        cin >> P[i].first >> P[i].second;
    }

    // Khởi chạy backtracking
    backtrack(1, 0, 0, 0, 0);

    // In kết quả
    cout << max_profit << endl;
    for (int x : best_selection) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

