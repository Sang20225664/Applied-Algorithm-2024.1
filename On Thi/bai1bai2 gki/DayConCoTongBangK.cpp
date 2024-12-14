#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool ok=0;
int x[100],a[100],n,k,visited[100],sum=0;
//su dung pos de cac cau hinh ko duoc lap lai
void Try(int i,int pos){
    for(int j=pos;j<=n;j++){
        x[i]=a[j];
        sum+=a[j];
        if(sum==k){
            ok=1;
            cout<<"[";
            for(int l=1;l<=i;l++){
                cout<<x[l];
                if(l!=i) cout<<' ';
            }
            cout<<"]";
            cout<<endl;
        }else Try(i+1,j+1);
        sum-=a[j];
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        memset(visited,0,sizeof(visited));
        Try(1,1);
        cout<<endl;
        if(!ok) cout<<"-1\n";
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[1001];
int x[1001];
vector<vector<int>> adj;
void inp(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
void Try(int u,int pos,int sum){
    if(sum==s){
        vector<int> ans;
        for(int i=0;i<u;i++){
            ans.push_back(x[i]);
        }
        adj.push_back(ans);
        return;
    }
    if(sum>=s || u >= n){
        return;
    }
    for(int i=pos;i<=n;i++){
        x[u]=a[i];
        Try(u+1,i+1,sum+a[i]);
    }
}
int main(){
    inp();
    Try(0,1,0);
    for(auto it:adj){
        cout<<'[';
        for(int k:it){
            cout<<k<<' ';
        }
        cout<<']';
        cout<<endl;
    }
    return 0;
}
*/
