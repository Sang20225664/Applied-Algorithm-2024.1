//Dem so luong day chan - day con co tong so phan tu chan (day con la lien tuc)
#include <bits/stdc++.h>
using namespace std;

//prefix
int main(){
    int n; cin >> n;
    int a[n];
    int even[n], odd[n];
    cin >> a[0];
    even[0] = 0;
    odd[0] = 0;
    if(a[0] % 2 == 0) even[0] = 1;
    else odd[0] = 1;
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) even[i] = even[i-1] + 1; //neu a[i] chan thi tang even len 1
        else even[i] = odd[i-1]; //neu a[i] le thi cong so tong le cua i-1 (le + le = chan)
        odd[i] = i + 1 - even[i]; //tinh lai so prefix le tai i
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += even[i];
    }
    cout << sum;
}

int NghiepDu(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += a[j];
            if(sum % 2 == 0) cnt++;
        }
    }
    cout << cnt;
}
