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
    
    int n;
    cin>>n;
    multiset<int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a.insert(x);
    }

    int ans = 0;
    for(int i = n; i >= 1; i--) {
        bool found = false;
        if(a.count(i)) {
            a.erase(a.find(i));
            continue;
        }
        for(int j = i; j <= 1e5+500; j += i) {
            auto it = a.upper_bound(j);
            if(it != a.end() && *it % (*it - i) == i) {
                found = true;
                ans++;
                a.erase(it);
                break;
            }
        }
        if(!found) {
            cout << -1 << nl;
            return;
        }
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

