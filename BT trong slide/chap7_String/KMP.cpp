#include <bits/stdc++.h>
using namespace std;

//Tiền xử lí mảng 'pi'
vector<int> computePi(const string &p){
    int m = p.length();
    vector<int> pi(m, 0);
    int k = 0; //độ dài của tiền tố dài nhất

    for(int q = 1; q < m; q++){ //xét từ q = 1 vì pi[0] = 0
        while(k > 0 && p[k] != p[q]){
            k = pi[k-1]; //quay laị vị trí dài nhất trc đó
        }
        if(p[k] == p[q]) k++;
        pi[q] = k;
    }
    return pi;
}

int kmp(string &p, string &t){
    int m = p.length();
    int n = t.length();

    vector<int> pi = computePi(p);
    int q = 0; //số kí tự khớp hiện tại
    int cnt = 0;

    for(int i = 0; i < n; i++){
        //Duyệt từng kí tự vb
        while( q> 0 && p[q] != t[i]){
            q = pi[q-1];
        }
        if(p[q] == t[i]) q++;
        if(q == m) { //số ktu khớp trùng độ dài xâu nhỏ -> đúng 1TH
            cnt++;
            q = pi[q-1];
        }
    }
    return cnt;
}

int main(){
    string t, p;
    getline(cin, p);
    getline(cin, t);

    cout << kmp(p, t);
}
