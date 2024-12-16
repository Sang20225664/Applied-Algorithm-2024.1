/*Tập T gồm m giảng viên từ 1 đến m
tập C gồm n lớp từ 1 đến n
mỗi khóa có crd[i] tín chỉ (i từ 1 đến n)
Mỗi giảng viên t (trong T) có dsach lớp có thể dạy tối thiểu LB[t] lớp
Tồn tại ds cặp lpws ko thể phân cùng 1 gv do trùng giờ
Khối lượng giảng dạy là tổng số tín của lớp đó, ko có 2 lớp trùng giờ cho cùng 1 giảng viên
-> Tìm cách phân công hết lớp học sao cho khối luoựng dạy lớn nhất giữa các giảng viên nhỏ nhất
Neeus ko đc in ra -1*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100;  // Giới hạn số lớp và số giảng viên
int m, n;  // m: số giảng viên, n: số lớp
int crd[N];  // Số tín chỉ của mỗi lớp
vector<int> canTeach[N];  // Danh sách lớp mà giảng viên có thể dạy
int LB[N];  // Số lớp tối thiểu mỗi giảng viên phải dạy
set<pair<int, int>> conflicts;  // Các cặp lớp trùng giờ

int load[N];  // Tổng tải trọng hiện tại của mỗi giảng viên
bool assigned[N];  // Lớp đã được gán hay chưa
int bestLoad = INT_MAX;

// Kiểm tra ràng buộc trùng giờ
bool checkConflict(int class1, int class2) {
    return conflicts.find({class1, class2}) != conflicts.end() ||
           conflicts.find({class2, class1}) != conflicts.end();
}

// Backtracking để phân lớp học
bool canAssign(int t, int maxLoad) {
    if (t == n + 1) {  // Đã phân hết các lớp
        int maxTeacherLoad = *max_element(load, load + m + 1);
        bestLoad = min(bestLoad, maxTeacherLoad);
        return true;
    }

    for (int teacher = 1; teacher <= m; teacher++) {
        if (find(canTeach[teacher].begin(), canTeach[teacher].end(), t) != canTeach[teacher].end()) {
            bool valid = true;
            for (int other = 1; other <= n; other++) {
                if (assigned[other] && checkConflict(t, other)) {
                    valid = false;  // Trùng giờ
                    break;
                }
            }

            if (valid && load[teacher] + crd[t] <= maxLoad) {
                load[teacher] += crd[t];
                assigned[t] = true;

                if (canAssign(t + 1, maxLoad)) return true;

                load[teacher] -= crd[t];
                assigned[t] = false;
            }
        }
    }
    return false;
}

bool isFeasible(int maxLoad) {
    memset(load, 0, sizeof(load));
    memset(assigned, false, sizeof(assigned));
    return canAssign(1, maxLoad);
}

void solve() {
    int totalCredits = accumulate(crd + 1, crd + n + 1, 0);
    int left = *max_element(crd + 1, crd + n + 1);  // Tải trọng nhỏ nhất
    int right = totalCredits;  // Tổng tải trọng lớn nhất

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isFeasible(mid)) {
            right = mid - 1;  // Tìm tải trọng nhỏ hơn
        } else {
            left = mid + 1;  // Không khả thi, tăng tải trọng
        }
    }

    if (bestLoad == INT_MAX) cout << -1 << endl;
    else cout << bestLoad << endl;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> crd[i];

    for (int i = 1; i <= m; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int x; cin >> x;
            canTeach[i].push_back(x);
        }
    }

    int p; cin >> p;  // Số cặp lớp trùng giờ
    for (int i = 0; i < p; i++) {
        int x, y; cin >> x >> y;
        conflicts.insert({x, y});
    }

    solve();
    return 0;
}
