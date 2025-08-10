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
bool check(vector<pi>& now) {
    for(int i = 0; i < 6; i++) {
        if(now[i].second != now[(i+1)%6].first) {
            return false;
        }
    }
    return true;
}
int ans = 0, sum = 0;
array<int,3> a[6];
vector<pi> now;
void recur(int i) {
    if(i == 6) {
        if(check(now)) {
            ans = max(ans, sum);
        }
        return;
    }

    for(int j = 0; j < 3; j++) {
        now.push_back(make_pair(a[i][(j-1+3)%3], a[i][(j+1)%3]));
        sum += a[i][j];
        recur(i+1);
        now.pop_back();
        sum -= a[i][j];
    }
}
void solve(){

    while(true) {
        ans = 0;
        sum = 0;
        for(int i = 0; i < 6; i++) {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        do {
            recur(0);
        }while(next_permutation(a,a+6));
        if(ans == 0) cout << "none";
        else cout << ans;
        cout << nl;
        string c; cin>>c;
        if(c == "$") break;
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

