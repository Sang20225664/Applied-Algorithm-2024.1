#include <bits/stdc++.h>
using namespace std;
int a[100000];
int seg[400000];
/*int getMax(int l, int r){
    int maxe = a[l];
    for(int i = l; i <= r; i++){
        maxe = max(maxe, a[i]);
    }
    return maxe;
}*/
void build(int i, int l, int r){ //xdung cay tại node i voi doan [l,r]
    if(l == r) seg[i] = a[l]; //gan gia tri node tai node la
    else{
        int mid = (l+r)/2;
        build(2*i, l, mid); //nua trai
        build(2*i + 1, mid + 1, r) ;//nua phai
        seg[i] = max(seg[2*i], seg[2*i +1]); //gia tri node hien tai la gtri lon nhat cua 2 node con
    }
}
void update(int id, int l, int r, int i, int v){ //cap nhat gtri vao segment tree
    if(l == r) seg[id] = v; //neu la node la thi gan luon gtri
    else{
        int mid = (l+r)/2;
        if(i <= mid) update(2*id, l, mid, i, v);
        else update(2*id + 1, r, mid, i, v);
        seg[id] = max(seg[id*2], seg[id*2+1]);
    }
}

int getMax(int id, int l, int r, int u, int v){
    if(u > r ||  v < l) return INT_MIN; //loai bo truong hop nhat ko hop le input
    if(u <= l && r <= v) return seg[id]; //tra ve gtri node
    int mid = (l + r)/2;
    return max(getMax(2 * id, l, mid, u, v), getMax(2 * id + 1,mid + 1, r, u , v) );
}

int main(){
    int n; cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    string cmd;
    build(1,1,n);
    int m; cin >> m;
    while(m--){
        cin >> cmd;
        if(cmd == "get-max") {
            int l, r; cin >> l >> r;
            cout << getMax(1, 1, n,l, r) << endl;
        }
        else if(cmd == "update") {
            int i, v;
            cin >> i >> v;
            update(1, 1, n, i, v);
        }
    }
    return 0;
}
