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
    
    string s,t;
    cin>>s>>t;

    int n = s.length(), tt = t.length();
    for(int i = 0; i < n; i++) {
        if(s[i] != t[0]) continue;
        int j = 1, ii = i;
        // go right
        int jj = j, iii = ii;
        jj = j, iii = ii;
        while(jj < tt && iii - 1 >= 0 && s[iii-1] == t[jj]) {
            iii--;
            jj++;
        }
        if(jj == tt) {
            cout << "YES" << nl;
            return;
        }
        while(j < tt && ii + 1 < n && s[ii+1] == t[j]) {
            ii++;
            j++;
            jj = j, iii = ii;
            while(jj < tt && iii - 1 >= 0 && s[iii-1] == t[jj]) {
                iii--;
                jj++;
            }
            if(jj == tt) {
                cout << "YES" << nl;
                return;
            }
        }
        while(j < tt && ii - 1 >= 0 && s[ii-1] == t[j]) {
            ii--;
            j++;
        }
        if(j == tt) {
            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
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

