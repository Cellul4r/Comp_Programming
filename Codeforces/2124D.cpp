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
    for(auto &x : a) {
        cin>>x;
    }

    if(k == 1) {
        cout << "YES" << nl;
        return;
    }

    vector<int> b = a;
    sort(all(b));
    // k-1th smallest
    int last = b[k-2];
    vector<int> c;
    for(int i = 0; i < n; i++) {
        if(a[i] <= last) {
            //cerr << a[i] << nl;
            c.push_back(a[i]);
        }
    }
    int l = 0, r = c.size() - 1;
    int op = c.size() - k + 1;
    while(l < r) {
        if(c[l] == c[r]) {
            l++;
            r--;
        } else if(c[l] != last && c[r] != last){
            cout << "NO" << nl;
            return;
        } else {
            op--;
            if(c[l] == last) l++;
            else r--;
        }
    }
    cout << (op >= 0 ? "YES" : "NO") << nl;
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

