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
    cin>>n;
    vector<pi> armors;
    for(int i = 0; i < n; i++) {
        int k;
        cin>>k;
        int now = 0;
        for(int j = 0, dec = 0; j < k; j++, dec++) {
            int x;
            cin>>x;
            now = max(now, x - dec);
        }
        armors.push_back(make_pair(now,k));
    }
    sort(all(armors));
    int ans = 0;
    for(int i = 0, now = 0; i < (int)armors.size(); i++) {
        ans = max(ans,armors[i].first - now + 1);
        now += armors[i].second;
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

