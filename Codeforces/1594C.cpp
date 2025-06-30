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
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a,b);
}
void solve(){
    
    int n;
    string s;
    char c;
    cin>>n>>c>>s;

    vector<int> ans;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] != c) {
            ans.push_back(n);
            break;
        }
    }
    if(s[n-1] != c) {
        ans.push_back(n-1);
    }

    if(ans.size() == 2) {
        // are there better?
        // do one operation!
        for(int i = 1; i <= n ;i++) {
            int cnt = 0;
            for(int j = i; j <= n; j += i) {
                cnt += s[j-1] != c;
            }
            if(cnt == 0) {
                ans = {i};
                break;
            }
        }
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x << " ";
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

