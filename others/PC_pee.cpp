#include<iostream>
using namespace std;

void solve() {

    string s;
    cin>>s;
    int cnt = 0;
    int n = s.size();
    for(int i = 0; i < n;i++) {
        if(s[i] != 'O') continue;
        if((i-1 == -1 || s[i-1] != 'X') && (i+1 == n || s[i+1] != 'X')) cnt++;
    }
    cout << cnt << '\n';
}
int main() {
    
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}

