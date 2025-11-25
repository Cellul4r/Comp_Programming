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
    
    string a,b,c; cin>>a>>b>>c;
    int ans = INF;
    map<string,int> cnt2;
    cnt2[a]++;
    cnt2[b]++;
    cnt2[c]++;
    ans = min(ans, 3 - max({cnt2[a],cnt2[b],cnt2[c]}));
    vector<int> m(10), p(10), s(10);
    auto f = [&](string k) {
        if(k[1] == 'm') {
            m[k[0]-'0'] = 1;
        }
        if(k[1] == 'p') {
            p[k[0]-'0'] = 1;
        }
        if(k[1] == 's') {
            s[k[0]-'0'] = 1;
        }
    };
    f(a),f(b),f(c);
    auto g = [&](vector<int>& cur) {
        for(int i = 1; i <= 7; i++) {
            int cnt = 0;
            for(int j = 0; j < 3; j++) {
                if(cur[i+j] != 1) cnt++;  
            }
            ans = min(ans, cnt);
        }

    };
    g(m),g(p),g(s);
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

