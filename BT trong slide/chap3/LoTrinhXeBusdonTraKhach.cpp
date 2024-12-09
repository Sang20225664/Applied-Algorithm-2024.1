//xe bus xphat từ điểm 0 -> tính lộ trình đưa đón n khách và quay về điểm 0 sao cho tổng độ dài quãng đường là ngắn nhất
/*khách i có điểm đón là i, điểm trả là i + n (1 = (1, n))
xe bus có k chỗ ngồi, số khách k vượt quá k
kc từ i đến j là d(i, j)*/

#include <bits/stdc++.h>
using namespace std;

int n, cap, c[1000][1000];
int x[1000];
bool visited[1000];
int load = 0, f = 0, f0 = INT_MAX, x0[1000], cmin = INT_MAX;

void input(){
    cin >> n >> cap;
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
            if(i!= j && cmin > c[i][j]) cmin = c[i][j];
        }
    }

}

bool check(int v, int k){
    if(visited[v]) return false;
    if(v > n && !visited[v-n]) return false; //v > n thi v la diem tra khach, chua duoc tham chung to ko hop le
    else if( v <= n && load + 1 > cap) return false; //neu qua tai trong cung k hopp le
    return true;
}

void Try(int k){
    for(int v = 1; v <= 2*n; v++){
        if(check(v, k)){
            x[k] = v;
            f += c[x[k-1]][x[k]];
            //x[k -1] la diem vua di, x[k] la diem tiep theo
            if(v <= n) load ++; else load --;
            //v<= n tuc la dang o diem don khach, ngc lai la dang tra khach
            visited[v] = true;
            if( k == 2*n) { //ktra tca cac diem da duoc chon
                if(f + c[x[2*n]][0] < f0) f0 = f + c[x[2*n]][0]; //ktra de cap nhat ki luc, cong them ca chi phi quay ve
                for(int i = 0; i<= 2*n; i++) x0[i] = x[i]; //luu lai lo trinh tot nhat
            }
            else if(f + (2*n-k+1)*cmin < f0) Try(k+1);
            //ktra xem co can tiep tuc tim kiem, neu chi phi hien tai cong chi phi uoc tinh nho hon ki luc thi goi try de tim tiep

            //hoan tac
            if(v <= n) load--; else load++;
            visited[v] = false;
            f-= c[x[k-1]][x[k]];
        }
    }
}

int main (){
    input();
    x[0] = 0;
    Try(1);
    cout << f0;
    return 0;
}
