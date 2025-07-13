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
    
    int pos = 1;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a % 2 == 1) {
        pos ^= 1;
    }
    if(b % 2 == 1) {
        pos ^= 1;
    }
    if(pos) {
        cout << "Tidak Tidak ";
        if(c != 0 || b) {
            cout << "Ya ";
        } else {
            cout << "Tidak ";
        }
        if(d != 0 || a) {
            cout << "Ya";
        } else {
            cout << "Tidak";
        }
    } else {
        cout << (a || d ? "Ya " : "Tidak ");
        cout << (b || c ? "Ya " : "Tidak ");
        cout << "Tidak Tidak";
    }
    cout << nl;
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

