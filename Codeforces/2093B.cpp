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
    
    string s;
    cin>>s;

    int n = s.size();
    int ans = 0, i = n - 1;
    while(i >= 0) {
        if(s[i] != '0') {
            i--;
            break;
        }
        i--;
        ans++;
    }
    while(i >= 0 && s[i] == '0') i--;
    for(int j = 0; j <= i; j++) {
        if(s[j] != '0') ans++;
    }
    cout << ans << nl;
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

