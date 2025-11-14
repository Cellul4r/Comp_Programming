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
    
    string s;
    cin>>s;
    int n = s.length();
    if(n == 1) {
        cout << 1 << nl;
        return;
    }
    
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '*') {
            if(s[i+1] == '<' || s[i+1] == '*') {
                ans = -1;
            }
        } else if(s[i] == '>') {
            if(s[i+1] == '<' || s[i+1] == '*') {
                ans = -1;
            }
        }
    }

    if(ans == -1) {
        cout << -1 << nl;
        return;
    }

    int left = 0, right = 0;
    bool canUse = false;
    for(int i = 0; i < n; i++) {
        if(s[i] != '<') {
            canUse = true;
        }
        if(!canUse && s[i] != '<') break;
        if(canUse && s[i] != '*') break;
        left++;
    }
    canUse = false;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] != '>') {
            canUse = true;
        }
        if(!canUse && s[i] != '>') break;
        if(canUse && s[i] != '*') break;
        right++;
    }
    cout << max(left,right) << nl;
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

