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
    for(auto &x : a) {
        cin>>x;
    }

    int idx = -1, max_ = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] > max_) {
            max_ = a[i];
            idx = i;
        }
    }

    int l = 0, r = 0;
    if(idx == n - 1) {
        l = r = idx;
        while(l > 0 && a[l - 1] >= a[0]) {
            l--;
        }
    } else {
        l = r = idx - 1;
        while(l > 0 && a[l-1] >= a[0]) {
            l--;
        }
    }

    if(n == 1) l = r = 0;
    for(int i = r + 1; i < n; i++) cout << a[i] << " ";
    for(int i = r; i >= l; i--) {
        cout << a[i] << " ";
    }
    for(int i = 0; i < l; i++) cout << a[i] << " ";
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

