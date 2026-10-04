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
    string s; cin>>s;
    vector<int> a(10);
    for(auto &x : s) {
        a[x-'0']++;
    }
    int l = 0, r = n;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        vector<int> b = a;
        int now = 0;
        while(now < mid && b[1] >= 2) {
            now++;
            b[1] -= 2;
        }
        // 11:...
        bool ok = true;
        if(now < mid) {
            if(b[0] < mid - now) {
                ok = false;
            }
            b[0] -= mid - now;
            // can format with 01,02,03,...,10:(...min)
            for(int i = 6; i <= 9 && now < mid; i++) {
                while(now < mid && b[i] >= 1) {
                    now++;
                    b[i] -= 1;
                }
            }
            for(int i = 5; i >= 0 && now < mid; i--) {
                while(now < mid && b[i] >= 1) {
                    now++;
                    b[i] -= 1;
                }
            }
            if(now < mid) {
                ok = false;
            }
        }
        // try to construct minute
        now = 0;
        for(int i = 0; i <= 5; i++) {
            for(int j = 9; j >= 0; j--) {
                int k = min(b[i], b[j]);
                now += k;
                b[i] -= k;
                b[j] -= k;
            }
        }
        if(now < mid) {
            ok = false;
        }
        if(ok) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << nl;
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

