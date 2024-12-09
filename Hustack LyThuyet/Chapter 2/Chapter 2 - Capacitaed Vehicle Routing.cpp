
/*K xe tải sức chứa Q vận chuyển từ kho 0 đến khách 1, 2, ..., n.
Khách hàng i yêu cầu d[i] gói
c[i][j] : khoàng cách từ i đến j
giải pháp: tập hợp các tuyến đường, mỗi xe tải lket một tuyến đường, bdau từ kho, thăm 1 số khách hàng và trở lại kho
- Mỗi khách hàng đc thăm cxac bằng 1 tuyến đường
- Tổng số kiện hàng khách hàng yêu cầu của mỗi xe ko vượt quá sức chứa
--> tìm giải pháp có tổng kc di chuyển nhỏ nhất
* có thể có xe tải ko thăm khách nào (tuyến trống)
* Thứ tự lộ trình là qtrong: 01230 khac 03210
*/

#include <bits/stdc++.h>
using namespace std;

int n, k, q;
vector<vector<int>> bus; //bus[i] danh sach khang hang xe i phuc vu
vector<int> d;
int min_dis = 1e9;
vector<vector<int>> c;

//kiem tra khach hang voi so luong hang la i co nhet duoc vao xe b
bool check(int i, int b){
    int sum = 0;
    for(auto cus : bus[b]){
        sum += d[cus]; //tong so hang hoa hien tai
    }
    return sum + i <= q;
}

//Tinh khoang cach toi thieu cho xe b
int calMinDis(int b){
    int mindis = 1e9;
    if(bus[b].empty()){
        return 0;
    }
    sort(bus[b].begin(), bus[b].end()); //sắp xếp để cbi sinh hoán vị tiếp theo
    do{
        int curdis = 0;
        curdis += c[0][bus[b][0]]; //kc tu depot den khach hang dau tien
        for(int j = 0; j < bus[b].size() - 1; j++){ //xét từng cặp nên chỉ có size -1 cặp
            curdis += c[bus[b][j]][bus[b][j+1]]; //kc giua cac khach hang
        }
        curdis += c[bus[b].back()][0]; //kc tu khach cuoi quay lai depot
        mindis = min(mindis, curdis);
    }
    while(std::next_permutation(bus[b].begin(), bus[b].end())); //sinh hoán vị tca thứ tự thăm khách hàng
    return mindis;
}

//Hàm tính tổng qdg tối thiểu
void minTotalDis(){
    int total = 0;
    for(int i = 0; i < k; i++){
        total += calMinDis(i);
    }
    min_dis = min(min_dis, total);
}

//Thử phân khách u vào các xe
void Try(int i){
    for(int b = 0; b < k; b++){
        if(check(d[i], b)){
            bus[b].push_back(i);
            if(i == n) minTotalDis(); //neu tca khach hang duoc xu li thi tinh ket qua
            else Try(i + 1);
            bus[b].pop_back(); //backtracking
        }
    }
}

int main (){
    cin >> n >> k >> q;
    d.resize(n + 1); //khởi tạo mảng nhu cầu của khách
    bus.resize(k); //khởi tạo ds khách mỗi xe
    for(int i = 1; i <= n; i++) cin >> d[i];
    c.resize(n+1, vector<int>(n+1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) cin >> c[i][j];
    }
    Try(1);
    cout << min_dis;
}
