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
    
    int n,m,k; cin>>n>>m>>k;
    string s;
    vector<ll> a(n), b(m);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : b) {
        cin>>x;
    }
    cin>>s;
    sort(all(b));
    deque<array<ll,2>> left, right;
    for(int i = 0; i < n; i++) {
        // cal left
        auto it = upper_bound(all(b), a[i]);
        if(it != b.begin()) {
            it--;
            left.push_back({a[i] - *it, i});
        } else {
            left.push_back({LINF, i});
        }
        // cal right
        it = lower_bound(all(b), a[i]);
        if(it != b.end()) {
            right.push_back({*it - a[i], i});
        } else {
            right.push_back({LINF, i});
        }
    }
    sort(all(left));
    sort(all(right));
    vector<bool> vis(n, false);
    int now = 0;
    int run = 0;
    for(auto &x : s) {
        if(x == 'L') run--;
        else run++;
        if(run > 0) {
            while(!right.empty() && right[0][0] <= run) {
                auto r = right[0];
                right.pop_front();
                if(vis[r[1]]) continue;
                vis[r[1]] = true;
                now++;
            }
        } else if(run < 0) {
            while(!left.empty() && left[0][0] <= -run) {
                auto l = left[0];
                left.pop_front();
                if(vis[l[1]]) continue;
                vis[l[1]] = true;
                now++;
            }
        }
        cout << n - now << " ";
    }
    cout << nl;
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

