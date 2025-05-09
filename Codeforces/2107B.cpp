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
    ll k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    sort(all(a));

    if(a[n-1] - a[0] - 1 > k) {
        cout << "Jerry" << nl;
        return;
    }

    ll play = 0;
    if(a[n-1] - a[0] > k) {
        if(a[n-1] == a[n-2]) {
            cout << "Jerry" << nl;
            return;
        }
        ll val = a[n-1];
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] == val) {
                a[i]--;
                play++;
            } else {
                break;
            }
        }

    }
    
    //play += min(a[0],max(1ll * k - a[n-1] + a[0], 0ll)); 
    //cerr << play << nl;
    ll sum = 0;
    //a[0] = a[0] - min(a[0],max(1ll * k - a[n-1] + a[0], 0ll));
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    
    //cerr << sum << nl;
    int tom = 1;
    if(play & 1) {
        tom = 0;
    }

    if(sum & 1) {
        cout << (tom ? "Tom" : "Jerry") << nl;
    } else {
        cout << (tom ? "Jerry" : "Tom") << nl;
    }
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

