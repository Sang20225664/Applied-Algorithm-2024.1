#include <bits/stdc++.h>
using namespace std;
//4 huong di chuyen
int dx[4] = {-1, 1, 0, 0}; //trai phai
int dy[4] = {0, 0, -1, 1}; //len xuong

int bfs(int n, int m, int r, int c, vector<vector<int>> &a){
    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, 0}); //toa do cua o va so buoc di

    vector<vector<bool>> visit(n, vector<bool>(m, false));
    visit[r][c] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        if(x == 0 || x == n - 1 || y == 0 || y == m -1)
            return steps; //kiem tra neu o hien tai nam o bien va khong phai la tuong thi tra ve so buoc di    }
        //Duyet qua 4 huong
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 0 && !visit[nx][ny]){
                visit[nx][ny] = true;
                q.push({{nx, ny}, steps+1});
            }
        }
    }
    return -2;
}

int main (){
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>>a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    r--; c--; //chuyeẻn chỉ só về 0
    if(r == 0 || r == n-1 || c == 0 || c == m-1) cout << -1;
    else {
        int res = bfs(n, m, r, c, a);
        cout << res+1;
    }
    return 0;
}
