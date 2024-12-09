//Thực hiện k truy vấn RMQ(i, j) trả về chỉ số của phần tử nhỏ nhất trong mảng
// Sử dụng cây phân đoạn Segment Tree
#include <bits/stdc++.h>
using namespace std;

void preprocessRMQ(const vector<int>&a, vector<vector<int>> &m){  //const -> tránh thay đổi khi thao tác với mảng a (ko cần cũng được), truyền tham chiếu & (nên sử dụng)
    //khởi tạo sparse table
    int n = a.size();
    int logN = log2(n) + 1;
    m.assign(logN, vector<int>(n));  //ma trận m gồm logN hàng, mỗi hàng là một mảng kích thước N (N cột)

    //khởi tạo hàng đầu tiên của sparse table
    for(int j = 0; j < n; j++){
        m[0][j] = j;
    }

    //Tinhs toán mức cao hơn
    for(int i = 1; (1 << i) <= n; i++){
        for(int j = 0; j + (1 << i) -1 <= n; j++){
            if(a[m[i-1][j]] <= a[m[i-1][j+(1<<(i-1))]]) m[i][j] = m[i-1][j];
            else m[i][j] = m[i-1][j+ (1<<(i-1))];
        }
    }
}
int queryRMQ(const vector<int> &a, const vector<vector<int>>& m, int l, int r){
    int k = log2(r-l+1);
    int id1 = m[k][l];
    int id2 = m[k][r-(1<<k) + 1];
    return (a[id1] < a[id2]) ? id1 : id2;
}

int main (){
    // Dữ liệu đầu vào
    vector<int> arr = {2, 4, 6, 1, 6, 8, 7, 3, 3, 5, 8, 9, 1, 2, 6, 4};
    vector<vector<int>> M;

    // Tiền xử lý
    preprocessRMQ(arr, M);

    // Truy vấn
    int L = 4, R = 14;
    int resultIdx = queryRMQ(arr, M, L, R);

    // In kết quả
    cout << "Chi so cua phan tu nho nhat trong doan [" << L << ", " << R << "] la: " << resultIdx << endl;
    cout << "gia tri nho nhat: " << arr[resultIdx] << endl;

    return 0;
}
