#include <bits/stdc++.h>
using namespace std;
int main (){
    int n; cin >> n;
    set<int>s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);
    }
    string cmd;
    int v;
    while(cin >> cmd){
        if(cmd == "#") break;
        cin >> v;
        if(cmd == "min_greater_equal"){
            auto it = s.lower_bound(v);
            if(it == s.end()) cout << "NULL" << endl;
            else cout << *it << endl;
        }
        if(cmd == "min_greater"){
            auto it = s.upper_bound(v);
            if(it == s.end()) cout << "NULL" << endl;
            else cout << *it << endl;
        }
        if(cmd == "insert"){
            s.insert(v);
        }
        if(cmd == "remove")
            if(s.find(v) != s.end()) s.erase(v);
    }
    return 0;
}
