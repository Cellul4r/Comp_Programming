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
string f(string s) {
    int n = s.size();
    string res;
    for(int i = 0; i < n; i++) {
        if(i + 1 < n && s[i] == 'x' && s[i+1] == 'x') {
            i++;
            while(i+1 < n && s[i+1] == ')' && !res.empty() && res.back() == '(') {
                res.pop_back();
                i++;
            }
            res += "xx";
        } else {
            res += s[i];
        }
    }
    //cout << res << nl;
    return res;
}
void solve(){
    
    string a,b;
    cin>>a>>b;
    
    bool ok = (f(a) == f(b));
    cout << (ok ? "Yes" : "No") << nl;
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

