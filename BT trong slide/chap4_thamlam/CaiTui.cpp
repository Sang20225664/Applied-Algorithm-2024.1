#include <bits/stdc++.h>
using namespace std;

struct dovat {
    int val; // Giá trị của đồ vật
    int w;   // Trọng lượng của đồ vật
};

// Hàm so sánh các đồ vật dựa trên giá trị/đơn vị trọng lượng
bool compare(const dovat& a, const dovat& b) {
    return (double)a.val / a.w > (double)b.val / b.w;
}

// Hàm giải bài toán cái túi
void caiTui(int cap, vector<dovat>& d) {
    // Sắp xếp các đồ vật theo giá trị/đơn vị trọng lượng giảm dần
    sort(d.begin(), d.end(), compare);

    double total = 0.0; // Tổng giá trị thu được
    for (const auto& i : d) {
        if (cap >= i.w) {
            // Nếu còn đủ sức chứa, thêm toàn bộ đồ vật
            cap -= i.w; // Giảm sức chứa của túi
            total += i.val;
        } else {
            // Nếu không đủ sức chứa, chỉ thêm được một phần đồ vật
            total += i.val * ((double)cap / i.w);
            break; // Không còn sức chứa, thoát khỏi vòng lặp
        }
    }
    cout << "Gia tri toi da co the dat duoc: " << total << endl;
}

int main() {
    cout << "Nhap dung luong tui: ";
    int cap;
    cin >> cap;

    cout << "Nhap so luong do vat: ";
    int n;
    cin >> n;

    vector<dovat> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i].val >> d[i].w;
    }

    caiTui(cap, d); // Gọi hàm xử lý
    return 0;
}
