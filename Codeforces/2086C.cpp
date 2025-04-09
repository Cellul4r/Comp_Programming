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

void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) {
        int x;
        cin>>x;
        p[x] = i;
        a[i] = x;
    }

    vector<bool> vis(n+1);
    int now = 0;
    for(int i = 0; i < n; i++) {
        int k;
        cin>>k;
        while(!vis[k]) {
            now++;
            vis[k] = true;
            k = a[k];
        }
        cout << now << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

