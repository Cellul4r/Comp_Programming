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
int ask(int n, int x) {
    cout << "? " << x << " " << n;
    for(int i = 1; i <= n; i++) {
        cout << " " << i;
    }
    cout << endl;
    int dist; cin>>dist;
    return dist;
}
int ask(vector<int>& s, int x) {
    cout << "? " << x << " " << s.size();
    for(auto &k : s) {
        cout << " " << k;
    }
    cout << endl;
    int dist; cin>>dist;
    return dist;
}
void solve(){
    
    int n; cin>>n;
    int maxDist = 0, idx = -1;
    vector<int> a(n+1, 1);
    for(int i = 1; i <= n; i++) {
        a[i] = ask(n,i);
        if(a[i] > maxDist) {
            maxDist = a[i];
            idx = i;
        }
    }
    /*cout << maxDist << " " << idx << nl;
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << nl;*/
    vector<int> ans{idx};
    // what next of idx?
    // the distance with a[idx]-cur
    int cur = 1;
    while(cur < maxDist) {
        for(int i = 1; i <= n; i++) {
            if(a[i] != a[idx] - cur) {
                continue;
            }
            ans.push_back(i);
            if(ask(ans, idx) == (int)ans.size()) {
                break;
            }
            ans.pop_back();
        }
        cur++;
    }
    cout << "! " << ans.size();
    for(auto &x : ans) {
        cout << " " << x;
    }
    cout << endl;
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

