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

    int n; cin>>n;
    string s; cin>>s;
    vector<int> save;
    for(int i = 0; i <n; i++){
        if(s[i] == 'x') save.push_back(i);
    }
    for(int i = 0; i < n; i++) {
        if(i < save.size()) {
            cout << save[i] + 1 << nl;
        } else {
            cout << n << nl;
        }
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

