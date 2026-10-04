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
const int N =1e2+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,m;
int board[N][N];
int mn[N], mx[N];
void solve(){

    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '#') board[i][j] = 1;
        }
    }

    // no rotate
    memset(mn, INF, sizeof mn);
    memset(mx, 0, sizeof mx);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                mx[j] = max(mx[j], i);
            } else {
                mn[j] = min(mn[j], i);
            }
        }
    }
    bool ok = true;
    for(int i = 0; i < m; i++) {
        if(mx[i] > mn[i]) {
            ok = false;
        }
    }
    if(ok) {
        cout << n << " " << m << nl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << (board[i][j] ? '.' : '#');
            }
            cout << nl;
        }
        return;
    }

    // rotate left
    memset(mn, INF, sizeof mn);
    memset(mx, 0, sizeof mx);
    ok = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                mn[i] = min(mn[i], j);
            } else {
                mx[i] = max(mx[i], j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(mx[i] > mn[i]) {
            ok = false;
        }
    }

    if(ok) {
        cout << m << " " << n << nl;
        for(int j = m - 1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                cout << (board[i][j] ? '.' : '#');
            }
            cout << nl;
        }
        return;
    }

    // rotate left 2 times
    memset(mn, INF, sizeof mn);
    memset(mx, 0, sizeof mx);
    ok = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                mn[j] = min(mn[j], i);
            } else {
                mx[j] = max(mx[j], i);
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if(mx[i] > mn[i]) {
            ok = false;
        }
    }

    if(ok) {
        cout << n << " " << m << nl;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                cout << (board[i][j] ? '.' : '#');
            }
            cout << nl;
        }
        return;
    }


    // rotate left 3 times
    memset(mn, INF, sizeof mn);
    memset(mx, 0, sizeof mx);
    ok = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                mx[i] = max(mx[i], j);
            } else {
                mn[i] = min(mn[i], j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(mx[i] > mn[i]) {
            ok = false;
        }
    }

    if(ok) {
        cout << m << " " << n << nl;
        for(int j = 0; j < m; j++) {
            for(int i = n - 1; i >= 0; i--) {
                cout << (board[i][j] ? '.' : '#');
            }
            cout << nl;
        }
        return;
    }
    cout << "impossible";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

