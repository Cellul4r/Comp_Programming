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
    string s;
    cin>>n>>k>>s;
    vector<int> ans(n);
    int a = 0, b = 0;
    int bad = 0;
    for(auto &x : s) {
        if(x == '0') a++;
        else if(x == '1') b++;
        else bad++;
    }
    for(int i = 0; i < a; i++) {
        ans[i] = 1;
    }
    for(int i = n - 1; i >= n - b; i--) {
        ans[i] = 1;
    }
    
    for(int i = a; i < a + bad && i < n - b; i++) {
        ans[i] = 2;
    }
    for(int i = n - b - 1; i >= a && i >= n - b - bad; i--) {
        ans[i] = 2;
    }

    if(n == k) {
        for(auto &x : ans) x = 1;
    }
    for(auto &x : ans) {
        cout << (x == 0 ? '+' : (x == 1 ? '-' : '?'));
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

