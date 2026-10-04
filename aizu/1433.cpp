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
const int N =1e3+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,k;
array<int,3> a[N];
int ans[N], cnt[N];
void solve(){

    cin>>n>>k;
    for(int i = 1; i <= n; i++) {
        cin>>a[i][0]>>a[i][1];
        a[i][2] = i;
    }
    sort(a+1,a+n+1, [&](array<int,3>& i, array<int,3>& j) {
                return i[1] < j[1];
            });
    
    for(int i = 1; i <= n; i++) {
        int day = 1;
        while(day < a[i][0] || cnt[day] >= k) {
            day++;
        }

        //cerr << a[i][2] << " " << day << nl;
        ans[a[i][2]] = day;
        cnt[day]++;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << nl;
    }
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

