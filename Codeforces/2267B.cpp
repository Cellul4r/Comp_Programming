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
    vector<int> cnt(101, 0) ,cur(101, 0);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }
    for(int i = 100; i >= 0; i--) {
        if(cur[i] < cnt[i]) {
            for(int j = 0; j < cnt[i] - cur[i]; j++) {
                cout << i << " ";
            }
            cur[i] = cnt[i];
            for(int j = i - 1; j >= 1; j--) {
                while(cur[j] < cnt[j] && cur[j] < cnt[i]) {
                    cout << j << " ";
                    cur[j]++;
                }
            }
        } else {
            // already fill in the array
        }
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

