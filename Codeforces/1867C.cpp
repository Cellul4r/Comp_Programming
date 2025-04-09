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

int ask(int x) {

    cout << x << endl;

    int y;
    cin>>y;
    return y;
}
void solve(){
    
    int n;
    cin>>n;

    set<int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a.insert(x);
    }
    // find most consecutive right now
    int need = -1, prev_ = -1;
    for(auto &x : a) {
        if(x != prev_ + 1) {
            need = prev_ + 1;
            break;
        }
        prev_ = x;
    }
    if(need == 0) {
        int k = ask(0);
        return;
    }
    need = 0;
    while(true) {
        while(a.count(need)) {
            need++;
        }
        int y = ask(need);
        a.insert(need);
        if(y < 0) return;
        if(y < need) need = y;
        a.erase(y);
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

