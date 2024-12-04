//Thực hiện thao tác trên mảng
//update i v: gán a[i] = v
//getmax i j: gtri lớn nhất từ i đến j
//sử dụng cây phân đoạn
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int a[MAXN + 1], seg[4*MAXN];

void build(int i, int l, int r){
    if(l == r) seg[i] = a[l]; //neu la node la, gan gtri taij node
    else{
        int mid = (l + r)/2;
        build(2*i, l, mid); //2*i -> left child
        build(2*i + 1, mid + 1, r); //right
        seg[i] = max(seg[2*i], seg[2*i+1]); //lay gtri lon hon giua 2 node con
    }
}

void update(int id, int l, int r, int i, int v){
    if(l == r) seg[id] = v; //neu la node la thi gan luon
    else{
        int mid = (l + r) /2;
        if(i <= mid) update(2 *id, l, mid, i, v);
        else update(2*id + 1, mid + 1, r, i, v);
        seg[id] = max(seg[2*id], seg[2*id+1]);
    }
}

int getmax(int id, int l, int r, int i, int j){
    if(i > r || j < l) return INT_MIN; //neu gia tri nhap vao bi sai so voi dau cuoi
    if(i <= l && r <= j) return seg[id]; //neu doan hien tai nam hoan toan trong (i,j)
    int mid = (l + r) / 2;
    return max(getmax(2 * id, l, mid, i, j), getmax(2*id + 1, mid + 1, r, i, j));
}
int main() {
    int n;
    cin >> n; // Đọc số phần tử của mảng

    for (int i = 1; i <= n; i++) cin >> a[i]; // Nhập các phần tử của mảng
    build(1, 1, n); // Xây dựng cây Segment Tree cho đoạn [1, n]

    int m;
    cin >> m; // Đọc số truy vấn

    while (m--) {
        string cmd;
        cin >> cmd; // Đọc lệnh

        if (cmd == "get-max") {
            int l, r;
            cin >> l >> r;
            cout << getmax(1, 1, n, l, r) << endl; // Truy vấn giá trị lớn nhất trong đoạn [l, r]
        } else if (cmd == "update") {
            int i, v;
            cin >> i >> v;
            update(1, 1, n, i, v); // Cập nhật giá trị tại vị trí i thành v
        }
    }

    return 0;
}
