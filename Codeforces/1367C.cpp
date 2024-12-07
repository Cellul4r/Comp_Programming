#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ceil(ll a, ll b) {
    
    return (a + b - 1) / b;
}

ll cal(ll x, ll k) {
    
    return ceil(x,k+1);
}
void solve() {
        
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans = 0;
    ll now = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '1') {
            now-=k;
            if(now > 0) ans += cal(now,k);
            now = -k;
        } else {
            now++;
        }
    }
    if(now > 0) ans += cal(now,k);
    cout << ans << endl;
    // k = 1
    // 0 -> 1 -> 1
    // 00 -> 01 10 -> 1
    // 000 -> 101 (010) -> 2
    // 0000 -> 1010 0101 -> 2
    // 00000 -> 10101 (01010) -> 5
    // 001 -> 101 -> 1
    // 10001 -> 
    // 0010001 -> 1010101 -> 2 -> ceil(1/2) + ceil(1/2)
    // 0010000 -> 1010101 -> 3 -> ceil(1/2) + ceil(3/2)
    // consecutive zero is maximum = ceil(first/2) + ceil(second,2) + ...
    // for k = 1 and all string is zero -> maximum = ceil(n/2)
    // k = 2
    // 00 -> 10 01 -> 1
    // 000 ->100 010 001 -> 1
    // 0000 -> 1001 (0100) (0010) -> 2
    // 00000 -> 10010
    // consecutive zero maximum = ceil(n/(k+1)) :)
}
int main() {
	// your code goes here
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}
