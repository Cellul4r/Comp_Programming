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

int n,k;
vector<int> pos,neg;
void solve(){
    cin>>n>>k;
    pos.clear();
    neg.clear();
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(x < 0) {
            neg.push_back(-x);
        } else if(x > 0){
            pos.push_back(x);
        }
    }
    sort(all(pos));
    sort(all(neg));

    int p = pos.size(), nn = neg.size();
    ll posSum = 0, negSum = 0;
    for(int i = p - 1; i >= 0; i -= k) {
        posSum += pos[i];
    }
    for(int i = nn - 1; i >= 0; i -= k) {
        negSum += neg[i];
    }
    ll ans = 2 * (posSum + negSum);
    if(neg.empty() && pos.empty()) {
        cout << ans << nl;
        return;
    }
    if(neg.empty()) {
        ans -= pos[p-1];
    } else if(pos.empty()) {
        ans -= neg[nn-1]; 
    } else {
        ans -= max(pos[p-1],neg[nn-1]);
    }
    cout << ans << nl;
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


