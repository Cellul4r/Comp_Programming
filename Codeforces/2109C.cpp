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

int ask(string command, ll k) {

    cout << command;
    if(command != "digit") {
        cout << " " << k;
    }
    cout << endl;
    int res;
    cin>>res;
    return res;
}

int answer() {
    cout << "!" << endl;
    int res;
    cin>>res;
    return res;
}
void solve(){
    
    ll n;
    cin>>n;

    ask("mul", 999999999);
    ask("digit", 0);
    ask("add", n - 81);
    answer();

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

    cin>>t;
    while(t--)solve();

    return 0;
}

