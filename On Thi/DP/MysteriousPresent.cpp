/*n phong bi co chieu rong vao chieu cao pbi thứ i cao hơn của thứ i-1
Tạo chuỗi kthc lớn nhất sao cho pbi nhỏ nhất bỏ vừa thiệp có kthc w x h
In kthuoc chuỗi và chỉ số pbi theo thứ tự
*/
#include <bits/stdc++.h>
using namespace std;
struct Envelope{
    int w, h, id;
};

bool compare(const Envelope &a, const Envelope &b){
    if(a.w == b.w) return a.h > b.h;
    return a.w < b.w;
}

int LIS(vector<Envelope> &e, vector<int> &dp, vector<int> &par){
    int n = e.size();
    int maxlength = 0, lastid = -1;

    for(int i = 0; i < n; i++){
        dp[i] = 1; //do dai LIS tai moi vitri
        par[i] = -1; //ko co ptu truoc
        for(int j = 0; j < i; j++){
            //them pbi i sau pbi j
            if(e[i].h > e[j].h && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }

        if(dp[i] > maxlength){
            maxlength = dp[i];
            lastid = i;
        }
    }
    return lastid;
}

vector<int> trace(vector<int> &par, int lastid, vector<Envelope> &e){
    vector<int> res;
    while(lastid != -1){
        res.push_back(e[lastid].id);
        lastid = par[lastid];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n, w, h;
    cin >> n >> w >> h;
    vector<Envelope>e;
    for(int i = 0; i < n; i++){
        int wi, hi;
        cin >> wi >> hi;
        if(wi > w && hi > h) e.push_back({wi, hi, i + 1});
    }
    if(e.empty()){
        cout << 0 << endl;
        return 0;
    }
    sort(e.begin(), e.end(), compare);
    int m = e.size();
    vector<int> dp(m), par(m);

    // Tìm LIS và trả về chỉ số cuối cùng của chuỗi LIS
    int lastid = LIS(e, dp, par);

    // Truy vết kết quả từ chỉ số cuối cùng
    vector<int> result = trace(par, lastid, e);

    // In kết quả
    cout << result.size() << endl; // Độ dài của chuỗi
    for (int i : result) cout << i << " "; // Các chỉ số phong bì
    cout << endl;

    return 0;
}
