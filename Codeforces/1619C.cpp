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
    
    string a,s;
    cin>>a>>s;
    string b;
    while(a.length() < max(a.length(),s.length())) {
        a = '0' + a;
    }
    int i = a.length() - 1, j = s.length() - 1;
    while(i >= 0 && j >= 0) {
        int x = a[i] - '0', y = s[j] - '0';
        if(x > y) {
            int k = 10 - (x - y);
            if(j == 0 || s[j-1] - '0' != 1) {
                cout << -1 << nl;
                return;
            }
            b += k + '0';
            i--;
            j -= 2;
        } else {
            b += (y - x) + '0';
            i--;
            j--;
        }
    }

    if((i >= 0 && a[0] != '0') || (j >= 0 && s[0] != '0')) {
        cout << -1 << nl;
        return;
    }
    reverse(all(b));
    ll ans = 0;
    for(int i = 0; i < (int)b.length(); i++) {
        ans = ans * 10ll + (b[i] - '0');
    }

    cout << ans << nl;
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

