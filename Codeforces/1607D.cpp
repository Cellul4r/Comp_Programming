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
    vector<int> a(n);
    string s;
    for(auto &x : a) {
        cin>>x;
    }
    cin>>s;
    vector<int> red, blue;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            if(a[i] > n) {
                cout << "NO" << nl;
                return;
            }
            red.push_back(a[i]);
        } else {
            if(a[i] <= 0) {
                cout << "NO" << nl;
                return;
            }
            blue.push_back(a[i]);
        }
    }

    sort(all(red)), sort(all(blue));
    bool ok = true;
    int j = 0, k = 0, jj = blue.size(), kk = red.size();
    // j blue, k  red
    for(int i = 1; i <= n; i++) {
        if(j == jj && k == kk) {
            ok = false;
            break;
        }
        if(j == jj) {
            if(red[k] > i) {
                ok = false;
                break;
            }
            k++;    
        } else {
            if(blue[j] < i) {
                ok = false;
                break;
            }
            j++;
        }
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

