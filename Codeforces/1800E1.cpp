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
    assert(k == 3);

    string s,t;
    cin>>s>>t;

    if(n <= 3) {
        cout << (s == t ? "YES" : "NO") << nl;
    } else if(n == 4) {
        string a = "", b = "";
        a += s[0], a += s[3];
        b += t[0], b += t[3];
        sort(all(a));
        sort(all(b));
        if(a != b || s[1] != t[1] || s[2] != t[2]) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
        }
    } else if(n == 5) {
        string a = "", b = "";
        a += s[0], a += s[3], a += s[4], a += s[1];
        b += t[0], b += t[3], b += t[4], b += t[1];
        sort(all(a));
        sort(all(b));
        if(a != b || s[2] != t[2]) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
        }
    } else {
        sort(all(s));
        sort(all(t));
        cout << (s == t ? "YES" : "NO") << nl;
    }
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

