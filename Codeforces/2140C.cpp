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

    ll sumA = 0, sumB = 0;
    ll ans = -LINF;
    vector<array<int,2>> a, b;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        if(i & 1) {
            b.push_back({x,i});
            sumB += x;
        }
        else {
            a.push_back({x,i});
            sumA += x;
        }
    }
    ans = max(ans, sumA - sumB);
    if(n & 1) {
        ans = max(ans, sumA - sumB + n - 1);
    } else {
        ans = max(ans, sumA - sumB + n - 2);
    }
    sort(all(a), [&](array<int,2>& i, array<int,2>& j) {
                return 2ll * i[0] + i[1] < 2ll * j[0] + j[1];
            });
    sort(all(b), [&](array<int,2>& i, array<int,2>& j) {
                return 2ll * i[0] + i[1] > 2ll * j[0] + j[1];
            });

    int m = b.size(), k = a.size();
    if(n > 1) {
        ans = max(ans, sumA - sumB + 2ll * b[0][0] - 2ll * a[0][0] + abs(a[0][1] - b[0][1]));
        ans = max(ans, sumA - sumB + 2ll * b[m-1][0] - 2ll * a[k-1][0] + abs(b[m-1][1] - a[k-1][1]));
    }
    sort(all(a), [&](array<int,2>& i, array<int,2>& j) {
                return 2ll * i[0] - i[1] < 2ll * j[0] - j[1];
            });
    sort(all(b), [&](array<int,2>& i, array<int,2>& j) {
                return 2ll * i[0] - i[1] > 2ll * j[0] - j[1];
            });
    if(n > 1) {
        ans = max(ans, sumA - sumB + 2ll * b[0][0] - 2ll * a[0][0] + abs(a[0][1] - b[0][1]));
        ans = max(ans, sumA - sumB + 2ll * b[m-1][0] - 2ll * a[k-1][0] + abs(b[m-1][1] - a[k-1][1]));
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

