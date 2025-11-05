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
    if(k == n * n - 1) {
        cout << "NO" << nl;
        return;
    }
    vector<vector<int>> ans(n, vector<int>(n));
    
    int save = -1, col = -1;
    k = n * n - k;
    for(int i = n - 2; i >= 0; i -= 2) {
        for(int j = 0; j < n && k - 2 >= 0; j++) {
            ans[i][j] = 1;
            k -= 2;
            save = i;
            col = j;
        }
    }

    //cerr << save;
    assert(k <= n);
    for(int j = col+1; j < n && k > 0; j++) {
        ans[save+1][j] = 2;
        k--;
    }

    for(int j = 0; j < n && k > 0 && save - 1 >= 0; j++) {
        ans[save-1][j] = 1;
        k--;
    }
    cout << "YES" << nl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ans[i][j] == 0) {
                cout << 'U';
            } else if(ans[i][j] == 1) {
                cout << 'D';
            } else {
                cout << 'L';
            }
        }
        cout << nl;
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

