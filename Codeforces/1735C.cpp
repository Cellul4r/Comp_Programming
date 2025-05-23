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
    
    int n;
    string s;
    cin>>n>>s;
    vector<int> in(26,-1), out(26,-1);
    for(int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        if(in[x] != -1) continue;
        for(int j = 0; j < 26; j++) {
            if(out[j] != -1 || j == x) continue; 
            // find cycle
            bool cycle = false;
            int now = j;
            out[j] = x;
            in[x] = j;
            int k = 0;
            while(out[now] != -1) {
                k++;
                now = out[now];
                if(now == j) {
                    cycle = true;
                    break;
                }
            }
            if(cycle && k < 26) {
                out[j] = -1;
                in[x] = -1;
            } else {
                //cerr << x << " " << j << nl;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        s[i] = in[s[i]-'a'] + 'a';
    }
    cout << s << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

