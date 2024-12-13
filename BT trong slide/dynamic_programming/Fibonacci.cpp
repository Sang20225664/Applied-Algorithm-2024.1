#include <bits/stdc++.h>
using namespace std;

int iMem[1001];

int Fib(int n){
    if(n <= 2) return 1;
    if(iMem[n] != -1) return iMem[n];
    int res = Fib(n-1) + Fib(n-2);
    iMem[n] = res;
    return res;
}

int main(){
    fill(iMem, iMem+ 1000, -1);
    int n; cin >> n;
    cout << Fib(n);
}
