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
    vector<ll> a,b;
    for(int i = 0; i < 2 * n; i++) {
        int x,y;
        cin>>x>>y;
        if(x == 0) {
            a.push_back(abs(y));
        } else {
            b.push_back(abs(x));
        }
    }

    sort(all(a));
    sort(all(b));
    double ans = 0;
    for(int i = 0; i < n; i++) {
        ans += sqrt((double)a[i] * a[i] + b[i] * b[i]);
    }
    double ans2 = 0;
    for(int i = 0; i < n; i++) {
        ans2 += sqrt((double)a[i] * a[i] + b[n-i-1] * b[n-i-1]);
    }
    cout << fixed << setprecision(12) << min(ans,ans2) << nl;
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

