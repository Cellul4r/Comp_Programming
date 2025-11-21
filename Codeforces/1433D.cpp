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
    vector<int> a(n+1);
    map<int,vector<int>> cnt;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        a[i+1] = x;
        cnt[x].push_back(i+1);
    }
    int mx = 0, k = -1;
    int one = -1, two = -1;
    for(auto &[x,now] : cnt) {
        int y = now.size();
        if(y > mx) {
            mx = y;
            k = x;
        }
        if(one == -1) {
            one = now.back();
            now.pop_back();
        } else if(two == -1) {
            two = now.back();
            now.pop_back();
        }
    }
    if(mx == n) {
        cout << "NO" << nl;
        return;
    }

    assert(one != -1 && two != -1);
    cout << "YES" << nl;
    cout << one << " " << two << nl;
    for(int i = 1; i <= n; i++) {
        if(i == one || i == two) continue;
        if(a[i] == a[one]) {
            cout << two << " " << i;
        } else {
            cout << one << " " << i;
        }
        cout << nl;
    }
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

