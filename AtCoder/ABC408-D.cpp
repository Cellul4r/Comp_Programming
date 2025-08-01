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
    int one = 0, zero = 0, ans;
    for(auto &x : s) {
        if(x == '1') one++;
        else zero++;
    }
    ans = min(one, zero);
    vector<pi> interval;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') continue;
        int j = i;
        while(j < n && s[j] == '1') j++;
        interval.push_back(make_pair(i,j-1));
        i = j;
    }
    if(interval.empty()) {
        cout << 0 << nl;
        return;
    }
    int l = interval[0].first, r = interval[0].second;
    //cerr << l << " " << r << nl;
    int now = 0;
    for(int i = 1; i < (int)interval.size(); i++) {
        int a = interval[i].first, b = interval[i].second;    
        //cerr << a << " " << b << nl;
        if(b - a + 1 >= r - l + 1) {
            now += r - l + 1;
            l = a;
            r = b;
        } else if(a - l - 1 <= b - a + 1) {
            // merge it!
            now += a - l - 1; 
            r = b;
        } else {
            now += b - a + 1;
        }
    }
    if(now != -1) ans = min(ans,now);
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

