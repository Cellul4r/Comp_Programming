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
void solve(){
    
    int m,d;
    cin>>m>>d;

    if((m == 1 || m == 7) && d == 7) {
        cout << "Yes";
        return;
    }
    if(m == 3 && d == 3) {
        cout << "Yes";
        return;
    }
    if(m == 5 && d == 5) {
        cout << "Yes";
        return;
    }
    if(m == 9 && d == 9) {
        cout << "Yes";
        return;
    }
    cout << "No";
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

