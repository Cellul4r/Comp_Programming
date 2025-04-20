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

vector<int> digits[10];
bool recur(int i, int j, int m, string& s, string& l, string& r) {
    if(i == m) {
        return true;
    }
    cerr << i << " " << j << nl;
    bool ans = false;
    for(int k = l[i] - '0'; k <= r[i] - '0'; k++) {
        auto it = upper_bound(all(digits[k]), j);
        if(it == digits[k].begin() || digits[k].empty()) continue;
        int idx = --it - digits[k].begin();
        cerr << i << " " << k << " " << idx << " " << digits[k].size() << " " << j <<  nl;
        if(idx != (int)digits[k].size() && digits[k][idx] < j) {
            cerr << digits[k][idx] << nl;
            ans = ans || recur(i+1,digits[k][idx],m,s,l,r);
        }
    }
    return ans;
}
void solve(){
    
    for(int i = 0; i < 10; i++) digits[i].clear();
    string s,l,r;
    cin>>s;
    for(int i = 0; i < (int)s.size(); i++) {
        digits[s[i] - '0'].push_back(i);
    }
    int m;
    cin>>m>>l>>r;
    bool ans = recur(0,s.size(),m,s,l,r);
    cout << ans << nl;
    // li <= ri
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

