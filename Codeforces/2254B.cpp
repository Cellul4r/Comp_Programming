/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    // to block of strings
    vector<pair<char,int>> a;
    int cur = s[0], cnt = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] == cur) {
            cnt++;
            continue;
        }
        a.push_back({cur,cnt});
        cur = s[i];
        cnt = 1;
    }
    a.push_back({cur,cnt});
    int ans = a.size();
    for(int i = 1; i < (int)a.size() - 1; i++) {
        int &x = a[i].second;
        if(x != 1) continue;
        int now = a.size() - 1;
        if(a[i-1].first == a[i+1].first) {
            now--;
        }
        ans = min(ans, now);
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

