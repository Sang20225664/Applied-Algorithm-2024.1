#include <bits/stdc++.h>
using namespace std;

int main (){
    string text, word;
    string line;

    while(getline(cin, line)){
        text+= line + " "; //them dong moi vao text
    }
    for(char &c : text){
        if(!isalnum(c)) c = ' ';
    }
    map<string, int> mp;
    stringstream ss(text);
    while(ss >> word){
        mp[word]++;
    }
    for(auto &pair : mp)
        cout << pair.first << ' ' << pair.second << endl;
    return 0;
}
