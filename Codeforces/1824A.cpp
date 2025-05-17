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

void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<bool> seat(m);
    int one = 0, two = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(x == -1) {
            one++;
        } else if(x == -2) {
            two++;
        } else {
            seat[--x] = true;
        }
    }

    vector<int> pre(m);
    pre[0] = seat[0];
    for(int i = 1; i < m; i++) {
        pre[i] += pre[i-1] + seat[i];
    }
    int left = 0, right = 0, middle = 0;
    for(int i = 0; i < m; i++) {
        if(!seat[i]) continue;
        middle = max(middle, 1 + min(i,one + pre[i] - 1) + min(m - i - 1, two + pre[m - 1] - pre[i]));
    }
    int now = 0;
    while(one > 0 && now < m) {
        left++;
        if(seat[now++]) {
            continue;
        }
        one--;
    }
    for(int i = now; i < m; i++) if(seat[i]) left++;
    now = m - 1;
    while(two > 0 && now >= 0) {
        right++;
        if(seat[now--]) {
            continue;
        }
        two--;
    }
    for(int i = 0; i <= now; i++) if(seat[i]) right++;
    cout << max({left,right,middle}) << nl;
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

