#include <bits/stdc++.h>
using namespace std;

const int d = 256; //số lượng kí tự trong mã ASCII
const int q = 101; //số nguyên tố dùng để tránh tràn số
string t, p;
//Tính mã băm cho 1 chuỗi hoặc 1 đoạn
int hashcode(string &s, int start, int end){
    int c = 0; //giá trị băm
    for(int i = start; i <= end; i++){
        c = (c*d + s[i]) % q; //tinsh gtri băm bằng Horner
    }
    return c;
}

int KabinKarp(string &p, string &t){
    int cnt = 0;
    int n = t.length();
    int m = p.length();

    //Tinsh e = d^(m-1) % q để xử lí dịch mã băm
    int e = 1;
    for(int i = 0; i < m-1; i++){
        e = (e * d) % q;
    }

    //Tính mã băm của p và đoạn đầu tiên trong T
    int codep = hashcode(p, 0, m-1);
    int codet = hashcode(t, 0, m-1);
    for(int s = 0; s <= n-m; s++){
        //Neeus mã băm trùng thì so sánh từng ksi tự
        if(codet == codep){
            bool ok = true;
            for(int j = 0; j < m; j++){
                if(p[j] != t[s + j]){
                    ok = false;
                    break;
                }
            }
            if(ok) cnt++;
        }
        //Tính mã băm cho đoạn tiếp theo
        if(s < n - m){
            int f = (codet - t[s]*e) % q; //Loại bỏ ảnh hưởng của kí tự đầu tiên
            if(f < 0) f += q; //xử lí số dư âm
            codet = (f * d + t[s + m]) % q; //thêm kí tự mới
        }
    }
    return cnt;
}

int main(){
    getline(cin, p);
    getline(cin, t);
    cout << KabinKarp(p, t);
    return 0;
}
