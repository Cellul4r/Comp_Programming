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

typedef pair<int,int> pi;
void setIO(string);
void solve(){
    
    int n; cin>>n;
    string s; cin>>s;
    for(int i = -1; i <= 9; i++) {
        // intermediate value
        // d[k] <= i go into group A
        // d[k] >= i go into group B
        int mxA = -1, mxB = -1;
        bool ok = true;
        vector<int> ans(n, 0);
        for(int j = 0; j < n; j++) {
            int x =  s[j] - '0';
            if(x < i) {
                if(mxA > x) {
                    ok = false;
                    break;
                }
                ans[j] = 1;
                mxA = x;
            } else if(x > i){
                if(mxB > x) {
                    ok = false;
                    break;
                }
                mxB = x;
                ans[j] = 2;
            } else {
                // x == i
                if(mxA > x && mxB > x) {
                    ok = false;
                    break;
                }
                if(mxB <= x) {
                    mxB = x;
                    ans[j] = 2;
                } else {
                    mxA = x;
                    ans[j] = 1;
                }
            }
        }
        if(ok) {
            for(auto &x : ans) {
                cout << x;
            }
            cout << nl;
            return;
        }
    }
    cout << "-\n";
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


