/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    int n; cin>>n;
    string a,b; cin>>a>>b;
    // 1001100
    // 1000011 (0000111)
    // 0000111

    // 1001100
    // 0000111
    //
    // 0011100
    // 0000111

    // 0011100
    // 0010011
    
    // 00101100
    // 00100011
    
    // 00100011
    // 00100011
    int oddA = 0, evenA = 0, oddB = 0, evenB = 0;
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            oddA += a[i] == '1';
            oddB += b[i] == '1';
        } else {
            evenA += a[i] == '1';
            evenB += b[i] == '1';
        }
    }
    if(oddA == oddB && evenA == evenB) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

