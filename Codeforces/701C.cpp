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
    vector<bool> alpha(120);
    int pokemon = 0;
    for(int i = 0; i < n; i++) {
        if(!alpha[s[i]-'A']) {
            pokemon++;
            alpha[s[i]-'A'] = true; 
        }
    }

    int ans = INF;
    map<char,int> cnt;
    int l = 0, r = 0;
    int now = 0;
    while(l < n) {
        //cerr << l << " " << r << nl;
        while(r < n && now != pokemon) {
            if(cnt[s[r]] == 0) {
                now++;
            }
            cnt[s[r]]++;
            r++;
        }
        if(now == pokemon) ans = min(ans, r - l);
        cnt[s[l]]--;
        if(cnt[s[l]] == 0) now--;
        l++;
    }
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

