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
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    vector<pi> div;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] % (i + 1) == 0) {
            if(cnt == 0) {
                cout << "NO" << nl;
                return;
            }
            div.push_back(make_pair(i,cnt));
        } else {
            cnt++;
        }
    }

    for(auto &[x,y] : div) {
        //cerr << x << " " << y << nl;
        // a[x], has before cnt
        bool found = false;
        for(int j = x-1; j >= 1; j--) {
            if(a[x] % (j+1) != 0) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
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

