/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n,m; cin>>n>>m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
        }
    }

    int ans = m;
    int l = 1, r = m - 1;
    int target = INF;
    auto f = [&](int k) {
        multiset<int> cur;
        for(int i = 0; i < n; i++) {
            cur.insert(v[i]);
        }
        priority_queue<int, vector<int>, greater<>> pq;
        ll sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                if((int)pq.size() < k) {
                    sum += a[i][j];
                    pq.push(a[i][j]);
                    continue;
                }
                if(pq.top() < a[i][j]) {
                    sum -= pq.top();
                    sum += a[i][j];
                    pq.pop();
                    pq.push(a[i][j]);
                }
            }
            if(*cur.begin() <= sum) {
                return true;
            }
            cur.erase(cur.find(v[i]));
        }
        return false;
    };
    while(l <= r) {
        int mid = l + (r - l) / 2; 
        if(f(mid)) {
            target = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    ans = min(ans, target);
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

