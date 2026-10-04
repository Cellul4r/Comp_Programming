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
    
    int n; cin>>n;
    // suppose k actions
    // place 1 odd
    // k - 1 evens (odd + evens... = odds) 
    // using maximum 1 odd and maximum k - 1 evens
    // if no odd in the array answer is 0
    ll odd = 0;
    vector<ll> even{0};
    for(int i = 0; i < n; i++) {
        ll x; cin>>x;
        if(x % 2 == 1) {
            odd = max(odd, x);
        } else {
            even.push_back(x);
        }
    }
    int m = even.size() - 1;
    int cnt = n - m - 1;
    sort(all(even), greater<ll>());
    for(int i = 1; i < m; i++) {
        even[i] += even[i-1];
    }
    for(int k = 1; k <= n; k++) {
        if(odd == 0) {
            cout << 0 << " ";
            continue;
        }
        ll ans = 0;
        if(m >= k - 1) {
            ans = odd + (k - 2 >= 0 ? even[k-2] : 0);
        } else {
            int needOdd = k - m - 1;
            int idx = m - 1;
            if(needOdd % 2 == 1 && idx >= 0) {
                needOdd++;
                idx--;
            }
            //cerr << needOdd << nl;
            if(needOdd <= cnt && needOdd % 2 == 0) {
                ans = odd + (idx >= 0 ? even[idx] : 0);
            }
        }
        cout << ans << " ";
    }
    cout << nl;
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

