#include <bits/stdc++.h>
using namespace std;
bool checknumber(string s){
    if(s.length() != 10) return false;
    for(int i = 0; i < s.length(); i++){
        if(s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

int counttime(string s, string b){
    int stime = 3600*((s[0] -'0')*10 + (s[1] -'0')) + 60*((s[3] -'0')*10 + (s[4] -'0')) + (s[6] -'0')*10 + (s[7] -'0');
    int ftime = 3600*((b[0] -'0')*10 + (b[1] -'0')) + 60*((b[3] -'0')*10 + (b[4] -'0')) + (b[6] -'0')*10 + (b[7] -'0');
    return ftime - stime;
}
int main (){
    string from_number;
    string to_number;
    string date, from_time, end_time;
    string cmd;
    map<string, int> callcount;
    map<string, int>callduration;
    int totalcall = 0;
    bool check = true;
    while(cin >> cmd){
        if(cmd == "call"){
            cin >> from_number;
            cin >> to_number >> date >> from_time >> end_time;
            totalcall++;
            if(!checknumber(from_number) || !checknumber(to_number)){
             check = false;
            }
            callcount[from_number]++;
             callduration[from_number] += counttime(from_time, end_time);
        }
        else if(cmd == "?check_phone_number"){
                if(check) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(cmd == "?number_calls_from"){
            cin >> from_number;
            cout << callcount[from_number] << endl;
        }
        else if(cmd == "?number_total_calls") cout << totalcall << endl;
        else if(cmd == "?count_time_calls_from") {
            cin >> from_number;
            cout << callduration[from_number] << endl;
        }
        else if(cmd == "#") continue;
    }
}
