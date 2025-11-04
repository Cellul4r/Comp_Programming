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
    string s; cin>>s;
    // for each s[i] = '0'
    // when place in the permutation array
    // left side must has element x such that x > i
    // or right side must has element x such that x < i
    // then s[i] = '0' -> s[x] = '0'
    
    bool flag = true;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        //cerr << i << nl;
        if(i + 1 == n) {
            if(s[i] == '1') {
                ans[i] = i;
            } else if(s[i-1] == '1'){
                flag = false;
            } else {
                ans[i] = ans[i-1];
                ans[i-1] = i;
            }
        } else if(s[i] == '1') {
            ans[i] = i;
        } else if(s[i+1] == '1') {
            if(i > 0 && s[i-1] == '0') {
                ans[i] = ans[i-1];
                ans[i-1] = i;
            } else {
                flag = false;
            }
        } else {
            ans[i] = i + 1;
            ans[i+1] = i;
            i++;
        }
    }
    if(!flag) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    for(auto &x : ans) {
        cout << x + 1 << " ";
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

