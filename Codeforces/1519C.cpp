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
    
    int n;
    cin>>n;

    vector<vector<ll>> uni(n+1);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        uni[a[i]].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        sort(all(uni[i]));
        reverse(all(uni[i]));
        for(int j = 1; j < (int)uni[i].size(); j++) {
            uni[i][j] += uni[i][j-1];
        }
    }
    
    vector<ll> ans(n+1);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < (int)uni[i].size(); j++) {
            int sz = j + 1;
            ans[j+1] += uni[i][uni[i].size() / sz * sz - 1];
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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

