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
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    vector<array<int,2>> ans, now;
    int i = 0;
    while(i < n) {
        int j = i;
        int mx = a[j];
        while(j+1 < n && a[j+1] == mx + 1) {
            mx = a[++j];
        }
        int idx = j;
        while(j - i + 1 < mx) {
            j++;
        }
        //cerr << i << " " << j << " " << mx << " " << (idx - i + 1) << nl;
        assert(j <= n);
        now.push_back({mx, mx - (idx - i + 1)});
        i = j + 1; 
    }

    int prev = -1;
    int cnt = 0;
    for(int i = (int)now.size() - 1; i >= 0; i--) {
        if(prev == -1) {
            prev = now[i][1];
            ans.push_back({2,now[i][1]});
            cnt += now[i][1];
        } else {
            int k = (prev + now[i][0] - 1) / now[i][0] * now[i][0]; 
            k = k - prev;
            prev += k + now[i][1];
            ans.push_back({2,k+now[i][1]});
            cnt += k + now[i][1];
        }
        cnt++;
        ans.push_back({1,now[i][0]});
    }
    reverse(all(ans));
    assert(cnt <= 2*n);
    cout << cnt << nl;
    for(auto &[x,y] : ans) {
        if(x == 1) {
            cout << x << " " << y << nl;
        } else {
            for(int i = 0; i < y; i++) {
                cout << 2 << nl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

