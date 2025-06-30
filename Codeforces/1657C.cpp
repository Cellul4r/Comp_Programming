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
    cin>>n>>s;

    int l = 0, op = 0;
    while(l + 1 < n) {
        if(s[l] == '(' || (s[l] == ')' && s[l+1] == ')')) {
            l += 2;
        } else {
            int r = l + 1;
            while(r < n && s[r] != ')') {
                r++;
            }
            if(r == n) break;
            l = r + 1;
        }
        op++;
    }

    cout << op << " " << n - l  << nl;
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

