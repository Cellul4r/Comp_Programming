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
   
    int m,k;
    char c;
    cin>>m>>c>>k;
    int ans = 0;
    int cnt = 0;
    int now = c - 'A';
    vector<int> note(m);
    for(int i = 0; i < m; i++) {
        note[i] = i % 26;
        if(note[i] == now) cnt++;
    }
    while(cnt != k) {
        ++ans;
        for(int i = 0; i < m; i++) {
            note[i] += (i+1);
            note[i] %= 26;
            if(note[i] == now) cnt++;
        }
    }
    cout << ans << nl;
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

