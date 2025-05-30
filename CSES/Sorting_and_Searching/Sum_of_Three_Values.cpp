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

    int n,x;
    cin>>n>>x;
    vector<pi> p(n);
    for(auto &x : p) cin>>x.first;
    for(int i = 0; i < n; i++) p[i].second = i;
    sort(all(p));
    int a=-1,b,c;
    for(int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        int want = x - p[i].first;
        while(l < r) {
            if(l == i) {
                l++;
                continue;
            }
            if(r == i) {
                r--;
                continue;
            }
            if(p[l].first + p[r].first == want) {
                a = p[i].second, b = p[l].second, c = p[r].second;
                break;
            } else if(p[l].first + p[r].first < want) {
                l++;
            } else {
                r--;
            }
        }
    }
    if(a == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << a+1 << " " << b+1 << " " << c+1;
    }
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

