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
    
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    sort(all(a));

    auto f = [&](int x) {
        int bomb = 0;
        int i = 0;
        while(i < n) {
            bomb++;
            int placeBomb = a[i] + x;
            int j = i+1;
            while(j < n && (a[j] >= placeBomb - x && a[j] <= placeBomb + x)) {
                j++;
            }
            i = j;
        }
        //cerr << x << " " << bomb << nl;
        return bomb <= k;
    };
    int l = 0, r = 1e9+5;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
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

