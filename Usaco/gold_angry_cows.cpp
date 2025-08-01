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
        x *= 2;
    }
    sort(all(a));

    auto f = [&](int x) {
        int l = 0, r = 2e9;
        while(l < r) {
            // place bomb at position mid (least pos) can it go bomb to the right?
            int mid = l + (r - l) / 2;
            bool ok = true; 
            int cur = mid, now = 0, rad = x;
            // can it go to the right
            while(cur < a.back()) {
                while(now + 1 < n && a[now + 1] <= cur + rad) now++;
                if(cur == a[now]) {
                    ok = false;
                    break;
                }
                cur = a[now];
                rad -= 2;
            }

            if(ok) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int cur = l, now = n - 1, rad = x;
        while(cur > a[0]) {
            while(now - 1 >= 0 && a[now - 1] >= cur - rad) now--;
            if(a[now] == cur) {
                return false;
            }
            cur = a[now];
            rad -= 2;
        }
        return true;
    };
    int l = 0, r = 2e9;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << fixed << setprecision(1) << (l / 2.0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    setIO("angry");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

