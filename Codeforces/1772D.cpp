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

    vector<int> b = a;
    sort(all(b));
    if(a == b) {
        cout << 0 << nl;
        return;
    }
    reverse(all(b));
    if(a == b) {
        cout << a[0] << nl;
        return;
    }

    int diff = -1;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > a[i+1]) {
           diff = max(diff,(a[i] + a[i+1] + 1) / 2);
        }
    }

    for(int i = 0; i < n; i++) {
        a[i] = abs(a[i] - diff);
    }

    for(int i = 0; i < n - 1; i++) {
        if(a[i] > a[i+1]) {
            cout << -1 << nl;
            return;
        }
    }

    cout << diff << nl;
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

