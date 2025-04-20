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
    
    int n,m,l,r;
    cin>>n>>m>>l>>r;

    int a = 0, b = 0, cnt = 0;
    for(int i = 0; i < abs(l) && cnt < m && a > l; i++) {
        a--;
        cnt++;
    }
    for(int i = 0; i < abs(r) && cnt < m && b < r; i++) {
        b++;
        cnt++;
    }
    cout << a << " " << b << nl;
    assert(b - a == m);
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

