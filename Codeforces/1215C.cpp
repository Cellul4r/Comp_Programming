/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    // aa
    // bb
    // ba
    // ba
    // 1.) if sum of some character is odd (in string s, and t) -> answer = -1
    // for each character 'c' let sum count = x
    // string s'count for c must have x / 2
    // string t'count for c must have x / 2
    int n; cin>>n;
    string s, t; cin>>s>>t;
    // each position only need at most 2 operation to make s[i] = t[i]
    // fuck string only has A and B!!!
    // 0 operation -> s[i] = t[i]
    // 1 operation -> there exist j > i such that s[i] = s[j] -> swap(t[i], s[j]) -> now(t[i], t[j])
    // 2 operation -> there exist j > i such that no s[i] = s[j] && s[i] = t[j] -> swap(s[j], t[j]), swap(t[i], s[j])
    // now (s[j] is with t[i])
    // for generality
    //a    a
    //b    b
    //a    b
    //b    a
    deque<int> a,b;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) continue;
        if(s[i] == 'a') {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    if((a.size() + b.size()) % 2 != 0) {
        cout << -1 << nl;
        return;
    }
    vector<array<int,2>> ans;
    while(!a.empty()) {
        int i = a.front();
        a.pop_front();
        int j;
        if(!a.empty()) {
            j = a.front();    
            a.pop_front();
        } else {
            j = b.front();
            b.pop_front();
            ans.push_back({j,j});
        }
        ans.push_back({j,i});
    }
    while(!b.empty()) {
        int i = b.front();
        b.pop_front();
        int j;
        if(!b.empty()) {
            j = b.front();    
            b.pop_front();
        } else {
            j = a.front();
            a.pop_front();
            ans.push_back({j,j});
        }
        ans.push_back({j,i});
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x[0] + 1 << " " << x[1] + 1 << nl;
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

