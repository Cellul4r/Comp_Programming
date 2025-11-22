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
    
    string s; cin>>s;
    int n = s.length();

    set<int> save; 
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') save.insert(i);
    }
    int ans = 0;
    vector<int> cur;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '(') {
            save.erase(i);
            continue;
        }
        if(save.empty()) break;
        ans = 1;
        cur.push_back(*save.begin());
        cur.push_back(i);
        save.erase(*save.begin());
    }
    cout << ans << nl;
    if(ans == 1) {
        sort(all(cur));
        cout << cur.size() << nl;
        for(auto &x : cur) {
            cout << x + 1 << " ";
        }
    }
    cout << nl;

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

