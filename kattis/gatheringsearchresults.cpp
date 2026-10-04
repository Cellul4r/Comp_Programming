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
    
    int n,k; cin>>n>>k;
    vector<double> sum(n);
    vector<int> ord(n);
    iota(all(ord), 0);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin>>x;
            sum[--x] += j;
        }
    }
    //for(auto &x : sum) x /= n;
    sort(all(ord), [&](int i, int j) {
                return sum[i] < sum[j];
            });
    for(auto &x : ord) {
        cout << x + 1 << " ";
    }
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

