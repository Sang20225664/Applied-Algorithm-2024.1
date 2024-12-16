/*Ng dùng gửi lên hệ thống tên của mình
Nếu tên không tồn tại trong csdl sẽ đc chèn vào và nhận phản hồi OK
Nếu tên đã tồn tại thì hệ thống gửi tên mới: các số bdau bằng 1 đc thêm vào tên,
    trong các số này số i ít nhất được tìm thấy để tên i chưa tồn tại
Input: n , n dòng chứa các tên
Output: phản hồi hệ thống*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    unordered_map<string, int> mp;
    while(n--){
        string name; cin >> name;
        if(mp.find(name) == mp.end()){
            cout << "OK" << endl;
            mp[name] = 0;
        }
        else {
            mp[name]++;
            cout << name << mp[name] << endl;
        }
    }
    return 0;
}
