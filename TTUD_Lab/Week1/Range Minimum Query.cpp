#include<bits/stdc++.h>
using namespace std;
const int Max=1e6+5;
int n;
int A[Max];
int m[30][Max];
int Q , x, y;
int sum=0;
void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
}
void preCompute(){
    for(int i=0;i<n;i++){
        m[0][i]=i;
    }
    for(int i=1;(1<<i)<=n;i++){
        for(int j=0;j+(1<<i)-1<n;j++){
            if(A[m[i-1][j]]<A[m[i-1][j + (1<<(i-1))]]){
                m[i][j]=m[i-1][j];
            } else m[i][j]=m[i-1][j+(1<<(i-1))];
        }
    }
}
void solve(){
    cin >> Q;
    int k;
    for(int i=0;i<Q;i++){
        cin >> x >> y;
        k = log2(y-x + 1);
        if(A[m[k][x]]<A[m[k][y-(1<<k)+1]]){
            sum = sum + A[m[k][x]];
        } else sum =sum + A[m[k][y-(1<<k)+1]];
    }
    cout << sum;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //  freopen("chapter2/file/RMQ.txt","r",stdin);
    input();
    preCompute();
    solve();
    // cout << endl;
    // for(int i=1;(1<<i)<=n;i++){
    //     for(int j=0;j+(1<<i)-1<n;j++){
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
