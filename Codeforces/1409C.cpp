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
    
    // 10 20 30 40 50
    // a2 - a1 = a3 - a2
    // 2 * a2 = a1 + a3
    // a3 - a2 = a4 - a3
    // 2 * a3 = a3 + a4
    // 2 * a2 = a1 + a4
    int n,x,y;
    cin>>n>>x>>y;
    int ans = INF;
    vector<int> a;
    for(int i = 1; i <= y - x; i++) {
        vector<int> b{x,y};
        int k = x;
        for(; k + i < y && (int)b.size() < n; k += i) {
            b.push_back(k + i);
        }

        k = x;
        for(; k - i >= 1 && (int)b.size() < n; k -= i) {
            b.push_back(k - i);
        }

        k = y + i;
        for(; (int)b.size() < n; k += i) {
            b.push_back(k);
        }

        sort(all(b));
        bool ok = true;
        int mx = b[n-1];
        bool xx = false, yy = false;
        for(int j = 0; j < n; j++) {
            if(b[j] == x) xx = true;
            if(b[j] == y) yy = true;
        }

        for(int j = 1; j < n; j++) {
            if(b[j] - b[j-1] != i) {
                ok = false;
            }
        }
        if(ok && xx && yy && mx < ans) {
            a.clear();
            for(int j = 0; j < n; j++) {
                a.push_back(b[j]);
            }
            ans = min(ans, mx);
        }
    }
    for(auto &x : a) {
        cout << x << " ";
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

