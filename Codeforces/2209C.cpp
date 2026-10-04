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
int n;
int ask(int i, int j) {
    assert(i >= 1 && i <= 2*n);
    assert(j >= 1 && j <= 2*n);
    cout << "? " << i << " " << j << endl;
    int x; cin>>x;
    assert(x != -1);
    return x;
}
void answer(int k) {
    cout << "! " << k << endl;
}
void solve(){
    
    // we have hidden array a with 2n element
    // 1..n (n element)
    // and 0 ... 0 (n element)
    cin>>n;
    for(int i = 1; i <= n-2; i++) {
        int now = ask(2*i-1, 2*i);
        if(now == 1) {
            answer(2*i-1);
            return;
        }
    }
    // we not found any array it must be on index 1 or n + 1
    int now = ask(2*(n-2)+1, 2*(n-2)+2);
    if(now == 1) {
        answer(2*(n-2)+1);
        return;
    }
    now = ask(2*(n-2)+2, 2*(n-2)+3);
    if(now == 1) {
        answer(2*(n-2)+2);
        return;
    } 
    now = ask(2*(n-2)+1, 2*(n-2)+3);
    if(now == 1) {
        answer(2*(n-2)+1);
        return;
    } 
    answer(2*n);
    // 0 0 0 2 1 4 3 0
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

