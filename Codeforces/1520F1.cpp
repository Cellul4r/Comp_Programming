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
int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x;
    cin>>x;
    return x;
}
void solve(){
    
    int n,t;
    cin>>n>>t;
    assert(t == 1);
    int k;
    cin>>k;
    int l = 1, r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        int now = mid - ask(1,mid);
        if(now < k) {
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
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

