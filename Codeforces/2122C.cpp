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
    vector<array<ll,3>> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i][0]>>a[i][1];
        a[i][2] = i + 1;
    }
    sort(a.begin(), a.end(), [](array<ll,3> a, array<ll,3> b) {
                if(a[0] != b[0]) return a[0] < b[0];
                return a[1] < b[1];
            });
    sort(a.begin(), a.begin() + n / 2, [](array<ll,3> a, array<ll,3> b) {
                return a[1] < b[1];
            });
    sort(a.begin() + n / 2, a.end(), [](array<ll,3> a, array<ll,3> b) {
                return a[1] > b[1];
            });
    ll ans1 = 0, ans2 = 0;
    vector<pi> ans11, ans22;
    for(int l = 0; l < n / 2; l++) {
        int r = n / 2 + l;
        ans11.push_back(make_pair(a[l][2],a[r][2]));
        //cout << a[l][2] + 1 << " " << a[r][2] + 1 << nl;
        //cerr << l << r << " " << abs(a[l].first - a[r].first) + abs(a[l].second - a[r].second) << nl;
        ans1 += abs(a[l][0] - a[r][0]) + abs(a[l][1] - a[r][1]);
    }
    for(int l = 0; l < n / 2; l++) {
        int r = n - l - 1;
        ans22.push_back(make_pair(a[l][2],a[r][2]));
        //cout << a[l][2] + 1 << " " << a[r][2] + 1 << nl;
        //cerr << l << r << " " << abs(a[l].first - a[r].first) + abs(a[l].second - a[r].second) << nl;
        ans2 += abs(a[l][0] - a[r][0]) + abs(a[l][1] - a[r][1]);
    }

    if(ans2 > ans1) {
        swap(ans11, ans22);
        swap(ans1,ans2);
    }
    for(auto &[x,y] : ans11) {
        cout << x << " " << y << nl;
    }
    //cout << ans << nl;
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

