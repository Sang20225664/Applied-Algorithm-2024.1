//Tìm số lượng ít nhất các đồng tiền để đổi được số tiền x với các mệnh giácố định
#include <bits/stdc++.h>
using namespace std;

void doiTien(int x, const vector<int>&menhgia){
    vector<int> res;
    for(int i = menhgia.size() -1; i >= 0; i--){  //xét từ mệnh giá lớn nhất
        while(x >= menhgia[i]){
            x-= menhgia[i];
            res.push_back(menhgia[i]);
        }
    }
    if(x > 0) cout <<"Khong doi duoc" << endl;
    else{
        cout <<"cac dong tien da sd: ";
        for(int t : res){
            cout << t << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int>menhgia = {1, 5, 10, 25, 100};
    int x;
    cout << "Nhap so tien can doi: ";
    cin >> x;
    doiTien(x, menhgia);
    return 0;
}
