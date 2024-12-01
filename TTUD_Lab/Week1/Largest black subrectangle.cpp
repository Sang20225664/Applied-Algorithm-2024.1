#include <bits/stdc++.h>
using namespace std;

//tinh dien tich lon nhat cua hcn (lay theo cot, chua quan tam o trang den)
int LargestArea(vector<int>& h){
    h.push_back(0); //them so 0 o cuoi de dam bao tinh du het cac cot
    int maxArea = 0;
    stack<int>id; //chi so cua cac cot

    //Duyet tat ca cac cot
    for(int i = 0; i < h.size(); i++){
        //Khi chieu cao cua cot hien tai nho hon chieu cao cua cot tren dinh stack,
        //lay ra cac cot tu stack de tinh dtich hcn
        while(!id.empty() && h[i] < h[id.top()]){
            int htop = h[id.top()]; //chieu cao cua cot tren dinh stack
            id.pop(); //loai bo cot khoi stack

            //tinh chieu rong cua hcn voi chieu cao h
            int w = id.empty() ? i : i - id.top() - 1;  //chieu rong bang chi so i neu stack rong
            maxArea = max(maxArea, htop*w);
        }
        id.push(i); //them chi so cua cot hien tai
    }
    h.pop_back(); //xoa so 0 da them trc do
    return maxArea;
}

//Tinh dien tich hcn con lon nhat bao ham o den
int blackArea(vector<vector<int>>& a){
    if(a.empty()) return 0; //ktra mang co rong khong
    int n = a.size();
    int m = a[0].size();
    vector<int>h(m, 0); //chieu cao cac cot;
    int maxArea = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1) h[j] ++;
            else h[j] = 0;
        }
        maxArea = max(maxArea, LargestArea(h));
    }
    return maxArea;

}
int main (){
    int n, m; cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int res = blackArea(a);
    cout << res;
    return 0;
}
