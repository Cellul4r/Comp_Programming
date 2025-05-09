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
    
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(all(a));

    int l = 0, r = 1e9+5;
    int ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2, i = 0;
        int now = 0, val = -1;
        //cerr << mid << nl;
        while(i < n && now < 3) {
            if(val == -1) {
                val = mid + a[i];
            } else if(abs(val - a[i]) > mid) {
                now++;
                val = -1;
                continue;
            }
            i++;
        }
        
        if(i == n && now < 3) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    assert(ans != -1);
    cout << ans << nl;
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

