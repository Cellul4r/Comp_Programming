/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int op = 0;
    // op <= 10*n?
    vector<int> cur = a, prv = a;
    vector<int> ans;
    do {
        ans.push_back(*max_element(all(cur)) - *min_element(all(cur)));
        /*
        for(auto &x : cur) {
            cout << x << " ";
        }
        cout << nl;
        */
        prv = cur;
        vector<int> b;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                b.push_back(cur[i] xor cur[j]);
            }
        }
        sort(all(b));
        for(int i = 0; i < n; i++) {
            cur[i] = b[i];
        }
        op++;
    }while(prv != cur);
    //cout << op << nl;
    for(int i = 1; i <= q; i++) {
        int x; cin>>x;
        if(x >= (int)ans.size()) {
            cout << ans.back() << nl;
        } else {
            cout << ans[x] << nl;
        }
    }
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

