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

void solve(){

    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    sort(all(a));
    
    for(int i = 0; i < m; i++) {
        ll aa,b,c;
        cin>>aa>>b>>c;
        if(c <= 0) {
            cout << "NO" << nl;
            continue;
        }
        
        int l = 0, r = n - 1;
        int ans1 = -1, ans2 = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(a[mid] <= b) {
                ans1 = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 0, r = n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(a[mid] >= b) {
                ans2 = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if(ans1 != -1 && (b - a[ans1]) * (b - a[ans1]) - 4ll * aa * c < 0) {
            cout << "YES" << nl;
            cout << a[ans1] << nl;
        } else if(ans2 != -1 && (b - a[ans2]) * (b - a[ans2]) - 4ll * aa * c < 0) {
            cout << "YES" << nl;
            cout << a[ans2] << nl;
        } else {
            cout << "NO" << nl;
        }
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

