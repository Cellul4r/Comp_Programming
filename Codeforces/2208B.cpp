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
    
    int n,k,p,m; cin>>n>>k>>p>>m;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    int now = 0;
    deque<int> cur;
    for(int i = 0; i < n; i++) {
        cur.push_back(i);
    }
    p--;
    int ans = 0;
    while(now < m) {
        int idx = -1;
        for(int i = 0; i < k; i++) {
            if(cur[i] == p) {
                idx = i;
                break;
            }
        }
        if(idx != -1) {
            if(now + a[p] <= m) {
                now += a[p];
                ans++;
                cur.erase(cur.begin() + idx);
                cur.push_back(p);
            } else {
                break;
            }
            continue;
        }
        sort(cur.begin(), cur.begin() + k, [&](int i, int j) {
                    return a[i] < a[j];
                });
        if(now + a[cur[0]] <= m) {
            now += a[cur[0]];
            int save = cur[0];
            cur.pop_front();
            cur.push_back(save);
        } else {
            break;
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

