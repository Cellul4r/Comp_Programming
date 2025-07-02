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
    
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> ans(n);
    int cur = k;
    for(int i = 0; i < n - 1 && cur > 0; i++) {
        if(s[i] == '1' && k % 2 == 1) {
            ans[i] = 1;
            cur--; 
        } else if(s[i] == '0' && k % 2 == 0){
            ans[i] = 1;
            cur--;
        }
    }

    ans[n-1] = cur;
    for(int i = 0; i < n; i++) {
        int play = k - ans[i];
        if(s[i] == '1' && play % 2 == 1) {
            s[i] = '0';
        } else if(s[i] == '0' && play % 2 == 1) {
            s[i] = '1';
        }
    }
    cout << s << nl;
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

