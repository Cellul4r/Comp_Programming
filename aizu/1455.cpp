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
vector<int> save[N];
bool vis[N];
int n;
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        save[x].push_back(i);
    }

    int ans = 0;
    for(int i = 1; i <= 100; i++) {
        int j = 0;
        while(j < (int)save[i].size()) {
            ans++;
            int k = j;
            int l = k+1; 
            while(l < (int)save[i].size()) {
                bool ok = true;
                for(int x = save[i][k]; x <= save[i][l]; x++) {
                    if(vis[x]) ok = false;
                }
                if(!ok) break;
                k++;
                l++;
            }
            j = k + 1;
        }
        for(int j = 0; j < (int)save[i].size(); j++) {
            vis[save[i][j]] = true;
        }
    }
    cout << ans << nl;
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

