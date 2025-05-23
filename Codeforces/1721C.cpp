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
    vector<int> a(n), b(n);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : b) {
        cin>>x;
    }

    vector<int> ans1(n), ans2(n);
    vector<int> save;
    for(int i = 0; i < n-1; i++) {
        if(b[i] - a[i+1] < 0) {
            save.push_back(i);
            //cerr << i << nl;
        }
    }
    for(int i = 0; i < n; i++) {
        int idx = lower_bound(all(b), a[i]) - b.begin();
        ans1[i] =  b[idx];
        ans1[i] -= a[i];

        ans2[i] = b[i] - a[i];
        int l = i+1, r = n-1;
        idx = i;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int kl = lower_bound(all(save), i) - save.begin();
            int kr = upper_bound(all(save), mid - 1) - save.begin();
            if(kl < kr) {
                r = mid - 1;
            } else {
                idx = mid;
                l = mid + 1;
            }
        }
        ans2[i] = b[idx] - a[i];
    }

    for(auto &x : ans1) {
        cout << x << " ";
    }
    cout << nl;
    for(auto &x : ans2) {
        cout << x << " ";
    }
    cout << nl << nl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

