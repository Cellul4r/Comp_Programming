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
string s,t;
int alpha[100];
void solve(){
    
    cin>>s>>t;
    for(int i = 0; i < (int)t.length(); i++) {
        alpha[t[i]-'A']++; 
    }
    
    for(int i = 1; i < (int)s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            if(alpha[s[i-1]-'A'] == 0) {
                cout << "No" << nl;
                return;
            }
        }
    }
    cout << "Yes" << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

