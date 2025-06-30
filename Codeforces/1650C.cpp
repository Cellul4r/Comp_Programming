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
    
    int n,m;
    cin>>n>>m;
    priority_queue<pair<int,int>> Q;
    vector<int> a(m), w(m);
    map<int,int> get;
    for(int i = 0; i < m; i++) {
        cin>>a[i]>>w[i];
    }
    
    for(int i = 0; i < m; i++) {
        get[a[i]] = i;
    }
    for(int i = 0; i < 2 * n; i++) {
        Q.push(make_pair(w[i],a[i]));
    }

    for(int i = 2 * n; i < m; i++) {
        int u = Q.top().first;
        if(w[i] < u) {
            Q.pop();
            Q.push(make_pair(w[i],a[i]));
        }
    }

    vector<int> ans;
    int sum = 0;
    while(!Q.empty()) {
        ans.push_back(Q.top().second);
        sum += Q.top().first;
        Q.pop();
    }

    sort(all(ans));
    cout << sum << nl;
    for(int i = 0; i < n; i++) {
        cout << get[ans[i]] + 1 << " " << get[ans[2*n-i-1]] + 1 << nl;
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

