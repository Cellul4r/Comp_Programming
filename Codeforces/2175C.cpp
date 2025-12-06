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
    
    string s,t; cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vector<int> cnt1(26), cnt2(26);
    for(auto &x : s) {
        cnt1[x-'a']++;
    }
    for(auto &x : t) {
        cnt2[x-'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(cnt2[i] < cnt1[i]) {
            cout << "Impossible" << nl;
            return;
        }
    }
    sort(all(t));
    //cout << t << nl;
    string tmp = s;
    sort(all(tmp));
    //cout << tmp << nl;
    string tt;
    int i = 0, j = 0;
    for(auto &x : t) {
        if(x == tmp[i]) {
            i++;
            continue;
        }
        tt += x;
    }
    i = 0;
    m = tt.size();
    string ans;
    //cerr << s << nl << tt << nl;
    while(i < n && j < m) {
        //cerr << i << " " << j << nl;
        if(s[i] <= tt[j]) {
            ans += s[i++];
        } else {
            ans += tt[j++];
        }
    }
    while(i < n) {
        ans += s[i++];
    }
    while(j < m) {
        ans += tt[j++];
    }
    cout << ans << nl;
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

