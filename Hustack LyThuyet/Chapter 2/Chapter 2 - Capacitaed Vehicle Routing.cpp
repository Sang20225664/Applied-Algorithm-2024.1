<<<<<<< HEAD
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
=======
#include <bits/stdc++.h>
using namespace std;
#define max_n 20
#define max_k 10

int n, K, q;
int d[11]; //so hang can giao cho khach i
int c[31][31]; //mtr kcach
int y[max_n]; //y[k] -> kh dau tien trong lo trinh cua xe k
int x[max_n]; //x[v] -> diem tiep theo sau v trong lo trinh
bool visited[max_n] = {false}; //cac khach hang da duoc phuc vu
int load[max_n]; //load[k] -> tai htai cua xe k
int segment; //tong so diem trong tca cac lo trinh
int cmin = 1e9 + 1 ; //kc nho nhat tim duoc
int curdis = 0; //tong kc htai trong lo trinh
int mindis = 1e9; //kc nho nhat giua 2 diem bat ki
int cus; //so luong khach hang trong tca cac lo trinh
int s = 0; //chi so bdau cua khach hang

void input(){
    cin >> n >> K >> q;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
            if(i != j) mindis = min(mindis, c[i][j]);
        }
        y[0] = 0; //lo trinh bdau tu kho
    }
}
//ktra xe k co the di chuyen tu u den v duoc khong
bool checkX(int v, int u, int k){
    if(visited[v] == true && v > 0) return false; //v da dc phuc vu
    if(load[k] + d[v] > q) return false; //khong du trong tai
}

void tryX(int u, int k){
    if(u == 0) { //neu da quay lai diem bdau
        if(k < k) tryX(y[k+1], k+1); //thu tiep neu con xe chua di
        return;
    }
    for(int v = 0; v<= n; v++){
    if(checkX(v, u, k)){
        x[u] = v;
        visited[v] = true;
        load[k] += d[v];
        segment ++;
        curdis += c[u][v];
        if(v == 0){
            if(k == K){
                if(segment == n + cus){ //neu tca kh da duoc tham
                    if(cmin > curdis) cmin = curdis; //cap nhat khoang cach toi thieu
                }
            }
            else{
                if(curdis + ( n + cus - segment) * mindis < cmin) tryK(y[k+1], k+ 1);
            }
        } else{
            if(cusdis + (n + cus - segment) * mindis < cmin) tryK(v, k);
        }
    }
}
}

>>>>>>> 77b5ec32c33827ff6819442c7450bfd77a7ce451
