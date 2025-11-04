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

    int n;
    cin>>n;
    if(n == 0) {
        cout << "YES" << nl;
        return;
    }

    vector<int> bits;
    while(n > 0) {
        bits.push_back(n % 2);
        n /= 2;
    }

    int l = 0, r = bits.size() - 1;
    bool canZero = true, ok = true;
    while(l < r) {
        if(bits[l] == 1) canZero = false;
        if(bits[l] == bits[r]) {
            l++;
            r--;
            continue;
        }
        if(bits[l] == 0) {
            if(canZero) {
                l++;
            } else {
                ok = false;
                break;
            }
        } else {
            ok = false;
            break;
        }
    }
    if(l == r && bits[l] == 1) {
        ok = false;
    }
    cout << (ok ? "YES" : "NO") << nl;
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

