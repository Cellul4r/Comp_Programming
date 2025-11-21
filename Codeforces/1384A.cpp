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
    
    int n; cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    // (1 2 4) 2
    // construct last string
    // aaaaaaaaaaaaaaaaaaaaaaa....
    // if at s[i] has a[i] <= length of next string s[i+1]
    // then a[i] = substring(s[i+1], length a[i]);
    // but if a[i] > length of next string s[i+1]
    // a (1)
    // aa (2)
    // aaaa (4)
    // aaaa (2)
    // aa
    // (3) (1 3)
    // aaa (3)
    // aaa (1)
    // a
    // aaa
    vector<string> ans(n+1);
    for(int i = 0; i < 200; i++) {
        ans[0] += "a";
    }
    for(int i = 1; i <= n; i++) {
        ans[i] = ans[i-1];
        ans[i][a[i-1]] = (ans[i][a[i-1]] == 'a' ? 'b' : 'a');
    }
    for(auto &x : ans) {
        cout << x << nl;
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

