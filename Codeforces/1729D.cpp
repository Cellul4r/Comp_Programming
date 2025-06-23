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
    vector<pi> a(n);
    for(auto &x : a) cin>>x.first;
    for(auto &x : a) cin>>x.second;
    int equal = 0;
    vector<int> less, more;
    for(auto &[x, y] : a) {
        if(x == y) {
            equal++;
        } else if(x > y) {
            less.push_back(x - y);
        } else {
            more.push_back(y - x);
        }
    }

    int ans = equal / 2;
    equal %= 2;
    sort(all(less), greater<int>());
    sort(all(more), greater<int>());
    int i = 0, j = 0;
    while(i < (int)less.size() && j < (int)more.size()) {
        if(less[i] > more[j]) {
            i++;
        } else {
            ans++;
            i++;
            j++;
        }
    }
    ans += (more.size() - j + equal) / 2;
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

