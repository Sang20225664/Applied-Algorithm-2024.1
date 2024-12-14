/*n khungr long, con thứ i số hiệu pi là hoán vị của 1, 2, .. n
Xâu s chỉ gồm C, H
    C; bạt đèn ở chuồng -> khủng long từ chuồng sang hành lang
    H: bật đèn hành lang -> khủng long từ hành lang vào chuồng
 -> Ghi ra số hiệu các con khủng long trong chuồng theo thứ tự từ cửa chuồng vào trong
    sau khi kthuc, tca khủng long ở trong chuồng
*/
#include <bits/stdc++.h>
using namespace std;
int main (){
    int n; cin >> n;
    vector<int> pos(n);
    for(int i = 0; i < n; i++) cin >> pos[i];
    stack<int> cage;
    queue<int> hall;
    for(int i = n- 1; i >= 0; i--) cage.push(pos[i]);
    string s; cin >> s;
    for(char c : s){
        if(c == 'C'){
            if(!cage.empty()){
                int dino = cage.top();
                cage.pop();
                hall.push(dino);
            }
        }
        else if( c == 'H'){
            if(!hall.empty()){
                int dino = hall.front();
                hall.pop();
                cage.push(dino);
            }
        }
    }
    vector<int>res;
    while(!cage.empty()){
        res.push_back(cage.top());
        cage.pop();
    }
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
}
