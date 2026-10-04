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
    
    int n; cin>>n;
    // remove such that no adjacent element has the same color
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int cnt = 1;
    int cur = a[0];
    vector<array<int,2>> b;
    for(int i = 1; i < n; i++) {
        if(a[i] == cur) {
            cnt++;
            continue;
        }
        b.push_back({cur,cnt});
        cnt = 1;
        cur = a[i];
    }
    if(cnt >= 1) {
        b.push_back({cur, cnt});
    }
    int mn = 0;
    int m = n;
    n = b.size();
    for(int i = 0; i < n; i++) {
        int k = max(0, b[i][1] - 2);
        mn += k;
        b[i][1] -= k;
    }
    bool found = false;
    for(int i = 0; i < n - 1; i++) {
        if(b[i][1] == 1) continue;
        if(b[i][1] == b[i+1][1]) {
            b[i][1] = 1;
            b[i+1][1] = 1;
            found = true;
            break;
        }
    }
    if(!found) {
        for(int i = 0; i < n - 1; i++) {
            if(b[i][1] == b[i+1][1]) continue;
            if(b[i][1] == 1) {
                if(i - 1 < 0 || b[i-1][0] != b[i+1][0]) {
                    b[i+1][1] = 1;
                    break;
                }
            } else {
                if(i + 2 >= n || b[i][0] != b[i+2][0]) {
                    b[i][1] = 1;
                    break;
                }
            }
        }
        // (1,2), (2,1)
    }
    for(int i = 0; i < n; i++) {
        mn += b[i][1] - 1;
    }
    cout << m - mn << nl;
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

