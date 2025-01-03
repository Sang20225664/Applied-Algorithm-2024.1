#include <iostream>
using namespace std;

// Hàm kiểm tra thứ tự của 3 điểm (dùng cho bài toán định hướng)
int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
    if (val == 0) return 0;           // Đồng thẳng
    return (val > 0) ? 1 : -1;        // 1 nếu theo chiều kim đồng hồ, -1 nếu ngược chiều
}

// Hàm kiểm tra nếu điểm P nằm trên đoạn thẳng AB
bool onSegment(int xA, int yA, int xB, int yB, int xP, int yP) {
    return (xP >= min(xA, xB) && xP <= max(xA, xB) && yP >= min(yA, yB) && yP <= max(yA, yB));
}

// Hàm kiểm tra hai đoạn thẳng (AB) và (CD) có cắt nhau không
bool doIntersect(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD) {
    int o1 = orientation(xA, yA, xB, yB, xC, yC);
    int o2 = orientation(xA, yA, xB, yB, xD, yD);
    int o3 = orientation(xC, yC, xD, yD, xA, yA);
    int o4 = orientation(xC, yC, xD, yD, xB, yB);

    // Kiểm tra các điều kiện giao nhau
    if (o1 != o2 && o3 != o4) return true;

    // Kiểm tra nếu điểm nằm trên đoạn thẳng
    if (o1 == 0 && onSegment(xA, yA, xB, yB, xC, yC)) return true;
    if (o2 == 0 && onSegment(xA, yA, xB, yB, xD, yD)) return true;
    if (o3 == 0 && onSegment(xC, yC, xD, yD, xA, yA)) return true;
    if (o4 == 0 && onSegment(xC, yC, xD, yD, xB, yB)) return true;

    return false;
}

int main() {
    int n;  // Số lượng bộ test
    cin >> n;

    while (n--) {
        // Nhập tọa độ 4 điểm
        int xA, yA, xB, yB, xC, yC, xD, yD;
        cin >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD;

        // Kiểm tra giao nhau và in kết quả
        if (doIntersect(xA, yA, xB, yB, xC, yC, xD, yD)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
