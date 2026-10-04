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
    
    // even index -> blue team
    // suppose there only 1 potato on the games
    // if 1 potato on even index
    // k = 1 -> 2->3 even win
    // k = 2 -> 2->2->3 even win
    // k = 3 -> 2->2->2->3 even win
    // for only 1 potatoes -> depend on parity index
    //
    // 2 potatoes?
    // assumption:
    // each team they try to hold the potato at most the time on k - 1 rounds and throw to next index (another team) on round k
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int e = 0, o = 0;
    n *= 2;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') continue;
        if(i % 2 == 0) {
            if(s[(i+1)%n] == '0') o++;
            else e++;
        } else {
            if(s[(i+1)%n] == '0') e++;
            else o++;
        }
    }
    cout << o << " " << e << nl;
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

