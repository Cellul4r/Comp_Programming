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
int n;
int a[N][N];
int k = -1;
int save;
void solve(){
    
    cin>>n;
    for(int i = 1; i <= n; i++) {
        int u,v,c;
        cin>>u>>v>>c;
        a[u][v] = c;
    }

    for(int i = 2; i <= n; i++) {
        if(a[1][i] || a[i][1]) {
            k = i;
            break;
        }
    }
    save = k;
    int ans1 = 0, ans2 = 0;
    int u = 1;
    ans1 += a[k][u];
    u = k;
    int v = 1;
    while(u != 1) {
        for(int i = 1; i <= n; i++) {
            if(i != v && (a[u][i] || a[i][u])) {
                k = i;
                break;
            }
        }
        ans1 += a[k][u]; 
        v = u;
        u = k;
    }
    u = 1;
    k = save;
    ans2 += a[u][k];
    v = u;
    u = k;
    while(u != 1) {
        for(int i = 1; i <= n; i++) {
            if(i != v && (a[u][i] || a[i][u])) {
                k = i;
                break;
            }
        }
        ans2 += a[u][k]; 
        v = u;
        u = k;
    }
    cout << min(ans1, ans2);
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

