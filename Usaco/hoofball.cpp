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

int n;
vector<int> a;
int findDirect(int i) {
    if(i == 0) {
        return i + 1;
    } else if(i == n - 1) {
        return i - 1;
    } else if(a[i] - a[i-1] > a[i+1] - a[i]) {
        return i + 1;
    } else {
        return i - 1;
    }
}
void solve(){
    
    cin>>n;
    a.resize(n);
    vector<int> passTo(n);
    for(auto &x : a) {
        cin>>x;
    }

    sort(all(a));
    // how to know that it is a cycle?
    // when direction is right -> , if previous has less distance the loop occurs
    // and also left direction...
    // then we just need to find the position of these cycles.
    for(int i = 0; i < n; i++) {
        // pass the ball to that cow!
       passTo[findDirect(i)]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(passTo[i] == 0) {
            // if this cow never get the ball 
            // he must be the start/source we should give the ball
            ans++;
        } else if(passTo[i] == 1 && passTo[findDirect(i)] == 1 && findDirect(findDirect(i)) == i) {
            i++;
            ans++;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

