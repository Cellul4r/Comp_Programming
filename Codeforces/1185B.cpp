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
    
    string s,t;
    cin>>s>>t;

    auto f = [&](string s) {
        vector<array<int,2>> a;    
        int now = -1;
        int cnt = 0;
        for(auto &x : s) {
            if(now == -1) {
                now = x;
                cnt = 1;
                continue;
            }
            if(now == x) {
                cnt++;
            } else {
                a.push_back({now,cnt});
                now = x;
                cnt = 1;
            }
        }

        if(cnt > 0) {
            a.push_back({now,cnt});
        }
        return a;
    };
    
    auto a = f(s);
    auto b = f(t);
    int i = 0, j = 0;
    while(i < (int)a.size() && j < (int)b.size()) {
        
        if(a[i][0] != b[i][0]) break;
        if(b[i][1] < a[i][1]) break;
        i++;
        j++;
    }
    cout << (i == (int)a.size() && j == (int)b.size() ? "YES" : "NO") << nl;
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

