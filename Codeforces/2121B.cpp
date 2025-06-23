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

void setIO(string);
void solve(){
    
    int n;
    string s;
    // a,b,c such that a + b + c = s
    // and b is substring of a + c 
    cin>>n>>s;
    vector<int> cnt(26);
    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    cnt[s[0] - 'a']--;
    cnt[s[n-1] - 'a']--;
    if(cnt[s[n-1] - 'a'] > 0 || cnt[s[0] - 'a'] > 0) {
        cout << "YES" << nl;
        return;
    }
    for(int i = 1; i < n - 2; i++) {
        int x = s[i] - 'a';
        cnt[x]--;
        if(cnt[x] > 0) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
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

