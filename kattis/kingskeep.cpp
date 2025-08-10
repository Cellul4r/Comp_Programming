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
double xx, yy;
void solve(){
    
    int n;
    cin>>n;
    vector<pair<double,double>> a(n);
    for(auto &x : a) {
        cin>>x.first>>x.second;
    }

    double ans = LINF;
    for(int i = 0; i < n; i++) {
        double dist = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            dist += sqrt((a[i].first-a[j].first) * (a[i].first - a[j].first) + (a[i].second-a[j].second)*(a[i].second-a[j].second));
        }
        dist /= 1.00 * (n-1);
        ans = min(ans,dist);
    }
    cout << fixed << setprecision(7) << ans;
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

