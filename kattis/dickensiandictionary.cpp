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
    
    string s; cin>>s;
    set<char>a{'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
    set<char>b{'y','u','i','o','p','h','j','k','l','n','m'};
    for(int i = 0; i < (int)s.size()-1; i++) {
        if(a.count(s[i]) && a.count(s[i+1])) {
            cout << "no";
            return;
        }
        if(b.count(s[i]) && b.count(s[i+1])) {
            cout << "no";
            return;
        }
    }
    cout << "yes";
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

