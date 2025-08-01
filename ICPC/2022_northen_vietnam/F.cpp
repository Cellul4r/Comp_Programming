#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef pair<int,int> pi;

void solve() {
   
    string s,f,l;
    cin>>s>>f>>l;

    if(s.substr(0,l.length()) == l && s.substr(l.length(),f.length()) == f) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
