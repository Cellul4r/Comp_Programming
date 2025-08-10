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
    string a,b; cin>>n>>a>>b;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int cur1 = 0, cur2 = 0;
        char tmp = a[i];
        // go right
        while(a[i] != b[i]) {
            cur1++;
            if(a[i] == 'Z') a[i] = 'A';
            else a[i]++;
        }
        // go left
        a[i] = tmp;
        while(a[i] != b[i]) {
            cur2++;
            if(a[i] == 'A') a[i] = 'Z';
            else a[i]--;
        }
        cnt += min(cur1,cur2);
    }
    cout << cnt;
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

