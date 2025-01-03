#include <bits/stdc++.h>
using namespace std;

const int N = 256;
int last[N];

void computeLast(string &p){
    for(int i = 0; i < p.length(); i++){
        last[p[i]] = i;
    }
}

int Boyer(string &p, string &t){
    int m = p.length();
    int n = t.length();

    computeLast(p);
    int s = 0; int cnt = 0;
    while(s <= n-m){
        int j = m-1;
        while(j >= 0 && p[j] == t[s + j]) j--;

        if(j < 0){ //lúc này xâu mẫu khớp với 1 đoạn vb
            cnt++;
            if(s + m < n) s += m - last[t[s+m]]; //nếu kí tự sau đoạn hiện tại vẫn nằm trong xâu vb
            else s++;
        }
        else{ //xâu không khớp
            int k = last[t[s+j]]; //vị trí gần nhất của kí tự xuất hiện gây lỗi
            s += max(1, j -k); //dịch xâu mẫu
        }
    }
    return cnt;
}

int main(){
    string p, t; cin >> p >> t;
    memset(last, -1, sizeof(last));
    cout << Boyer(p, t);
}
