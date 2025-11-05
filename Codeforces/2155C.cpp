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
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    auto f = [&](vector<int>& check) {
        vector<int> pref(n+1), suff(n+2);
        int ok = 1;
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + (check[i-1] == 0);
        }
        for(int i = n; i >= 1; i--) {
            suff[i] = suff[i+1] + (check[i-1] == 1);
        }
        for(int i = 1; i <= n; i++) {
            if(pref[i-1] + suff[i+1] + 1 != a[i-1]) {
                ok = 0;
                break;
            }
        }
        return ok;
    };

    vector<int> ans(n);
    int ways = 0;
    for(int i = 0, bits = 0; i < n; bits ^= 1) {
        int j = i + 1;
        ans[i] = bits;
        // check increasing
        while(j < n && a[j] - 1 == a[j-1]) {
            ans[j] = bits;
            j++;
        }
        // check decreasing
        if(j == i+1) {
            while(j < n && a[j] + 1 == a[j-1]) {
                ans[j] = bits;
                j++;
            }
        }
        //cerr << i << " " << j << nl;
        i = j;
    }

    ways += f(ans);
    for(auto &x : ans) {
        //cout << x << " ";
        x ^= 1;
    }
    //cout << nl;
    ways += f(ans);
    cout << ways << nl;
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

