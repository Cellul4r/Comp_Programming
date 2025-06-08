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
    vector<pi> a(n);
    for(auto &x : a) cin>>x.first;
    for(auto &x : a) cin>>x.second;
    sort(all(a));
    
    auto checkRight = [&](double pos, double timer) {
        for(int i = 0; i < n; i++) {
            if(a[i].first <= pos) continue;
            double need = fabs(a[i].first - pos) / a[i].second;
            if(need > timer) {
                return false;
            }
        }
        return true;
    };
    auto checkLeft = [&](double pos, double timer) {
        for(int i = 0; i < n; i++) {
            if(a[i].first >= pos) continue;
            double need = fabs(a[i].first - pos) / a[i].second;
            if(need > timer) {
                return false;
            }
        }
        return true;
    };
    double l = 0, r = 1e9+5;
    int iter = 0;
    while(iter < 100) {
        double m = l + (r - l) / 2.00;
        double lo = 0, hi = 1e9; 
        int iter2 = 0;
        while(iter2 < 100) {
            double mid = lo + (hi - lo) / 2.00;
            if(checkRight(mid, m)) {
                hi = mid;
            } else {
                lo = mid;
            }
            iter2++;
        }
        if(checkLeft(lo,m)) {
            r = m;
        } else {
            l = m;
        }
        iter++;
    }

    cout << fixed << setprecision(10) << l;
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

