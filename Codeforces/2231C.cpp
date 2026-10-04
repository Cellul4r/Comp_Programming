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
    
    // 16 8 8 7 7 6 3
    //  8 8 8 7 7 6 3 -> 1
    //  7 7 6 3 4 4 4 -> 4
    //   
    int n; cin>>n;
    vector<int> a(n);
    priority_queue<int> pq;
    int mn = INF;
    for(auto &x : a) {
        cin>>x;
        pq.push(x);
        mn = min(mn, x);
    }
    int ans = 0;
    bool flag = false;
    while(pq.top () > mn) {
        int x = pq.top();
        pq.pop();
        if(mn % 2 == 1 && mn + 1 == x) {
            flag = true;
            pq.push(x);
            break;
        }
        if(mn % 2 == 1) {
            while(x > mn + 1) {
                ans++;
                if(x % 2 == 1) {
                    x++;
                } else {
                    x /= 2;
                }
            }
        } else {
            while(x > mn) {
                ans++;
                if(x % 2 == 1) {
                    x++;
                } else {
                    x /= 2;
                }
            }
        }
        mn = min(x, mn);
        pq.push(x);
    }

    if(flag) {
        if(mn != 1) {
            // only one way odd number just + 1 it will all equal
            while(!pq.empty()) {
                int x = pq.top(); pq.pop();
                ans += (x % 2 == 1);
            }
        } else {
            // two ways 2-> 1, 1 -> 2
            int one = 0, two = 0;
            while(!pq.empty()) {
                int x = pq.top(); pq.pop();
                if(x % 2 == 0) {
                    one++;
                } else {
                    two++;
                }
            }
            ans += min(one, two);
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

