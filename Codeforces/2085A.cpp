/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void solve(){
    
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n == 1) {
        cout << "NO" << nl;
        return;
    }
    int cnt = 0;
    char maxChar = s[0];
    char minChar = s[0];
    for(int i = 1; i < n; i++) {
        maxChar = max(maxChar, s[i]);
        minChar = min(minChar, s[i]);
    }
    // if s[0] < s[n-1] we don't have to do anything
    if(s[n-1] < s[0]) {
        cnt++;
        // just swap to the min character to s[0]
    } else if(s[n-1] == s[0]) {
        // but if it equal what we have to do?
        // just swap first position to the min position
        if(minChar == maxChar) cnt = INF;
        int l = 0, r = n - 1;
        while(l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        if(l >= r) cnt++;
        if(l < r && s[r] < s[l]) {
            cnt++; 
        }
    }
    cout << (cnt <= k ? "YES" : "NO") << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

