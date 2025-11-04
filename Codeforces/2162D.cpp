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
ll ask(int type, int l, int r) {
    
    cout << type << " " << l << " " << r << endl;

    ll sum;
    cin>>sum;
    return sum;
}

void answer(int l, int r) {
    cout << "! " << l << " " << r << endl;
}

void solve(){
    
    int n;
    cin>>n;

    // first Query the sum of all arrays x,y (y - x) is the size of answer r - l + 1 choosen in p to do operation.
    ll sum = ask(2,1,n) - ask(1,1,n);
    int l = 1, r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        ll x = ask(1,1,mid), y = ask(2,1,mid);
        if(y - x == sum) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    int target = l;
    ll x = ask(1,1,target), y = ask(2,1,target);
    answer(target - (y - x) + 1, target);
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

