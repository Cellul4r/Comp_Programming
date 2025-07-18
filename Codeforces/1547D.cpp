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
    vector<int> a(n),ans(n);
    for(auto &x : a) {
        cin>>x;
    }

    int now = a[0];
    for(int i = 1; i < n; i++) {
        //cerr << now << " " << a[i] << nl;
        for(int j = 0; j < 30; j++) {
            int x = (1 << j);
            if((now & x) && (a[i] & x) == 0) {
                if(i == 2) {
                    //cerr << j << nl;
                }
                ans[i] |= (1 << j);
            }
        }
        now = a[i] ^ ans[i];
    }
    for(auto &x : ans) {
        cout << x << " ";
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

