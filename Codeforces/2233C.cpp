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
    
    int n,k; cin>>n>>k;
    string s; cin>>s;

    vector<bool> ans(n);
    int mn = INF;
    for(int i = 0; i <= k; i++) {
        vector<bool> now(n);  
        for(int j = 0, cnt = 0; j < n && cnt < i; j++) {
            if(s[j] == '(') {
                cnt++;
                now[j] = true;
            }
        }
        for(int j = n - 1, cnt = 0; j >= 0 && cnt < k - i; j--) {
            if(s[j] == ')') {
                cnt++;
                now[j] = true;
            }
        }
        int cur = 0;
        int open = 0;
        for(int j = 0; j < n; j++) {
            if(now[j]) continue;
            if(s[j] == '(') {
                open++;
            } else if(open > 0) {
                open--;
                cur += 2;
            }
        }
        //cout << i << " " << cur << nl;
        if(cur < mn) {
            for(int j = 0; j < n; j++) {
                ans[j] = now[j];
            }
            mn = cur;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << (ans[i] ? 1 : 0);
    }
    cout << nl;
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

