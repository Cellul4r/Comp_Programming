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
const int INF = 1e9+7;
const ll LINF = 1e18+7;
const int K = 1e5+1;
void setIO(string);

int N,M,H;
int T,P;
int x[K], te[K], h[K];
vector<pi> a[K];
vector<int> ans;
void solve(){
    
    cin>>N>>M>>H>>T>>P;
    for(int i = 0; i < M; i++) {
        cin>>x[i]>>te[i]>>h[i];
        x[i]--;
        a[x[i]].push_back(make_pair(te[i],h[i]));
    }
    for(int i = 0; i < N; i++) {
        sort(all(a[i]));
    }

    for(int i = 0; i < N; i++) {
        bool ok = true;    
        int sz = a[i].size();
        if(a[i][sz-1].second < H) continue;
        for(int j = 0; j < sz - 1; j++) {
            int t = a[i][j+1].first - 1, h = a[i][j].second;
            int water = (t < T ? 0 : P * (t - T + 1));
            if(h < water) {
                ok = false;
                break;
            }
        }
        if(ok) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x + 1 << " ";
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

