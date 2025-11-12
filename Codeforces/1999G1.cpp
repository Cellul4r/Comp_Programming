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

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int val;
    cin>>val;
    return val;
}
void solve(){

    int a = 1;
    int l = 2, r = 999;
    while(l < r) {
        int mid = l + (r - l) / 2ll;
        int res = ask(a,mid);
        if(res == a * mid) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << "! " << l << endl;
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

