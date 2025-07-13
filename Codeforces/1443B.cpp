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
    
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    int n = s.length(), one = -1;
    int ans = 0;
    vector<pi> interval;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0' && one != -1) {
            ans++;
            interval.push_back({one,i});
            one = -1;
        } else if(s[i] == '1') {
            if(one == -1) {
                one = i;
            }
        }
    }
    if(one != -1) {
        ans++;
        interval.push_back({one,n-1});
    }
    vector<int> connect;
    ans *= a;
    for(int i = 1; i < (int)interval.size(); i++) {
        connect.push_back(interval[i].first - interval[i-1].second);
        //cerr << interval[i].first << " " <<  interval[i-1].second << nl;
    }

    int now = ans;
    sort(all(connect));
    for(int i = 0; i < (int)connect.size(); i++) {
        now += connect[i] * b; 
        now -= a;
        ans = min(now,ans);
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

