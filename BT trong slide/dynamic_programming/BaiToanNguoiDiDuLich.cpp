/*n đỉnh và trọng số C[i][j] trên mỗi cặp đỉnh i, j
Tìm chu tình đi qua tca các đỉnh, mỗi đỉnh đúng 1 lần sao cho trọn số nhỏ nhất
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 20; //gioi han so luong dinh toi da
const int INF = 1e9;

int n;
int C[N][N];
int mem[N][1 << N]; //bang nho luu chi phi toi uu, voi N la so dinh, 1<< N la 2^N tuong ung so tap con cua N dinh

//Tinh chi phi nho nhat di qua tca ca diem r quay ve 0
int TSP(int i, int S){
    if(S == (1<< n) -1) return C[i][0]; //neu di het tca cac dinh thi quay ve 0
    if(mem[i][S] != -1) return mem[i][S];

    int res = INF;
    for(int j = 0; j <n; j++){
        if(S & (1 << j)) continue; //bo qua neu dinh j da duoc tham
        if(C[i][j] < INF)
        res = min(res, C[i][j] + TSP(j, S | (1<<j)));

    }
    return mem[i][S] = res;
}

void trace(int i, int S){
    cout << i << " -> ";
    if(S == (1 << n) -1){
        cout << "0" << endl;
        return;
    }

    for(int j = 0; j < n; j++){
        if(S & (1<<j)) continue;
        if(mem[i][S] == C[i][j] + TSP(j, S | (1 << j))){ //ktra neu dinh j la buoc tiep theo
            trace(j, S | (1 << j));
            break;
        }
    }
}

int main (){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> C[i][j];
        }
    }
    memset(mem, -1, sizeof(mem));

    int minCost = TSP(0, 1);
    cout << minCost << endl;
    trace(0, 1);
    return 0;
}
