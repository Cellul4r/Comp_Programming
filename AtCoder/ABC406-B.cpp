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

int n,k;
string now = "1";

string mult(string a, string b) {

    if(a.size() < b.size()) {
        swap(a,b);
    }
    reverse(all(a));
    reverse(all(b));
    int n = a.size(), m = b.size();
    vector<int> res(n+m+1);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res[i+j] += (b[i] - '0') * (a[j] - '0');
        }
    }

    string ans = "";
    for(int i = 0; i < n + m; i++) {
        res[i+1] += res[i] / 10;
        res[i] %= 10;
    }
    for(int i = 0; i < n + m + 1; i++) {
        ans += res[i] + '0';
    }
    reverse(all(ans));
    int idx = 0;
    while(idx < (int)ans.size() && ans[idx] == '0') {
        idx++;
    }

    ans = ans.substr(idx);
    if(k < (int)ans.size()) {
        ans = "1";
    }
    return ans;
}
void solve(){

    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        string a;
        cin>>a;
        now = mult(now, a);
    }

    cout << now << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

