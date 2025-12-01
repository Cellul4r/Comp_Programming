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
    vector<array<int,2>> a(n+1),b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i][0]>>a[i][1];  
    }
    for(int i = 1; i <= n; i++) {
        cin>>b[i][0]>>b[i][1];
    }

    for(int i = 1; i <= n; i++) {
        // assign a[i] to b[1]
        int tx = a[i][0] + b[1][0], ty = a[i][1] + b[1][1];
        set<array<int,2>> now; 
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            now.insert(a[j]);
        }

        bool ok = true;
        for(int j = 2; j <= n; j++) {
            int ax = tx - b[j][0], ay = ty - b[j][1];
            if(!now.count({ax,ay})) {
                ok = false;
                break;
            }
            now.erase({ax,ay});
        }
        if(ok) {
            cout << tx << " " << ty;
            return;
        }
    }
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

