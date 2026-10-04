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
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        if(x & 1) {
            odd++;
        } else {
            even++;
        }
    }
    
    if(even == 0) {
        cout << "Alice\n";
        return;
    }
    // case 2: only even number -> alice always win
    // if 0 < odd <= 2 and #even is even -> alice lose
    // if odd == 3 alice hurry to pick 1 odd then bob know he can't steal odd number since it has 2 number
    // if odd == 3 alice always win
    // if odd == 4 alice always win
    // if odd == 5
    // case 1: only odd number -> alice win only if n is odd
    // case 3: mix odd and even number ->
    //  3.1: alice pick last number with odd -> lose
    // how to prevent that? pick all odd first (with sum even) then even 
    // but if odd has #number is odd? 
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

