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

void solve(){
    
    int n,k;
    cin>>n>>k;

    string s,t;
    cin>>s>>t;

    bool flag = true;
    vector<int> alpha(26);
    for(int i = 0; i < n; i++) {
        if(i >= k || i + k < n) {
            alpha[s[i] - 'a']++;
            alpha[t[i] - 'a']--;
        } else {
            flag &= (s[i] == t[i]);
        }
    }
    for(auto &x : alpha) if(x != 0) flag = false;
    cout << (flag ? "YES" : "NO") << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

