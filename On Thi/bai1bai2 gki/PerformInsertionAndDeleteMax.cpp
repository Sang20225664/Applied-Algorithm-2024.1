//Tinh so luong day con k ptu ltiep cua day a sao cho trong so (tong tca cac ptu) moi day deu bang m
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int> pq;

    // Đọc các phần tử và thêm vào max-heap
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pq.push(a[i]);
    }
    string cmd;
    while(true){
        cin >> cmd;
        if (cmd == "insert"){
            int x;
            cin >> x;
            pq.push(x);
        }
        if (cmd == "delete-max"){
            cout << pq.top();
            pq.pop();
        }
        if (cmd == "*"){
            break;
        }
    }
    return 0;
}
