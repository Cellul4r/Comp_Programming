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
    
    // 1001 -> 0110
    // 0001 (8)
    // 0110 (7)

    //0100100100
    //1110100001

    // 1111100110
    // 0011110100
    // 1100010010 (operation)
    // if lgA >= lgB ok
    // else answer is -1

    int a,b;
    cin>>a>>b;
    if(a == b) {
        cout << 0 << nl << nl;
        return;
    }

    int lgA = 0, lgB = 0;
    while((1<<(lgA+1)) <= a) lgA++;
    while((1<<(lgB+1)) <= b) lgB++;
    if(lgA < lgB) {
        cout << -1 << nl << nl;
        return;
    }

    if(lgA > lgB) {
        cout << 2 << nl;
        cout << (a ^ b ^ (1 << lgA)) << " " << (1 << lgA) << nl << nl;
        return;
    }

    // lgA == lgB
    // 110010101
    // 110010000
    cout << 1 << nl;
    cout << (a ^ b) << nl << nl;
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

