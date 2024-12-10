#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CongViec {
    int batDau;
    int ketThuc;
};

bool compare(const CongViec& a, const CongViec& b) {
    return a.ketThuc < b.ketThuc;
}

void tapDoanThangKhongGiao(vector<CongViec>& congViec) {
    sort(congViec.begin(), congViec.end(), compare);
    int count = 0;
    int ketThucTruoc = 0;
    cout << "Cac cong viec duoc chon: ";
    for (const auto& cv : congViec) {
        if (cv.batDau >= ketThucTruoc) {
            cout << "[" << cv.batDau << ", " << cv.ketThuc << "] ";
            ketThucTruoc = cv.ketThuc;
            count++;
        }
    }
    cout << "\nTong so cong viec: " << count << endl;
}

int main() {
    vector<CongViec> congViec = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    tapDoanThangKhongGiao(congViec);
    return 0;
}
