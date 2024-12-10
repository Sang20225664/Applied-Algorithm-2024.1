//vật liệu hcn cao H, rộng W cắt thành n vlieu con hcn (h1, w1),..., (hn, wn)
//->Ktra xem có thể thực hiện được bao nhiêu phép cắt

#include<bits/stdc++.h>
using namespace std;

int H, W, n;
int used[11][11];
int h[11], w[11];
int x[11], y[11], o[11]; //toaj độ và trạng thái
bool res = false;
//Kiểm tra xem mảnh k có đặt vào tọa độ vx, vy với trạng thái vo hay ko
bool check(int vx, int vy, int vo, int k){
    int wk = w[k], hk = h[k];
    if(vo == 1) swap(wk, hk);
    if(vx + wk > W || vy + hk > H) return false;
    for(int i = vx; i <= vx + wk -1; i++){
        for(int j = vy; j <= vy + hk -1; j++){
            if(used[i][j]) return false;
        }
    }
    return true;
}

void mark(int vx, int vy, int vo, int k, bool v){
    int wk = w[k], hk = h[k];
    if(vo == 1) swap(wk, hk);
    for(int i = vx; i <= vx + wk -1; i++){
        for(int j = vy; j <= vy + hk -1; j++){
            used[i][j] = v; //true neu ghep, false neu thao ra
        }
    }
}

void Try(int k){
    if(res == true) return;
    for(int vo = 0; vo <= 1; vo++){
        int wk = w[k], hk = h[k];
        if(vo == 1) swap(wk, hk);

        for(int vx = 0; vx <= W-wk; vx++){
            for(int vy = 0; vy <= H -hk; vy++){
                if(check(vx, vy, vo, k)){
                    x[k] = vx, y[k] = vy, o[k] = vo;
                    mark(vx, vy, vo, k, true);
                    if(k == n) {
                        res = true;
                        return;
                    }
                    else Try(k + 1);
                    mark(vx, vy, vo, k, false);
                }
            }
        }
    }
}

int main (){
    cin >> H >> W;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i] >> w[i];
    }
    memset(used, false, sizeof(used));
    Try(1);
    cout << (res == true ? "1" : "0");
}
