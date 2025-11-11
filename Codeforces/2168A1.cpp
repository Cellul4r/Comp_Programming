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
void one() {
    int n;
    cin>>n;
    string s;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        s += (x - 1 + 'a');
    }
    cout << s;
}

void two() {
    string s;
    cin>>s;
    vector<int> ans;
    for(auto &x : s) {
        ans.push_back(x-'a'+1);
    }

    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x << " ";
    }
}

void solve(){
    
    string s;
    cin>>s;
    if(s == "first") {
        one();
    } else {
        two();
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

