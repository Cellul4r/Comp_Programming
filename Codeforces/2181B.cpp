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
    
    int n,m; cin>>n>>m;
    bool alice = true;
    priority_queue<int> a,b;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        a.push(x);
    }
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        b.push(x);
    }

    while(!a.empty() && !b.empty()) {
        int x = a.top(), y = b.top();
        if(alice) {
            b.pop(); 
            if(x < y) {
                y -= x;
                b.push(y);
            }
        } else {
            a.pop();
            if(y < x) {
                x -= y;
                a.push(x);
            }
        }
        alice = !alice;
    }
    cout << (a.empty() ? "Bob" : "Alice") << nl;
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

