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
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        if(abs(a[i] - a[i+1]) <= 1) {
            cout << 0 << nl;
            return;
        }
    }
    int ans = INF;
    for(int i = 0; i < n; i++) {
        for(int j = i - 1; j > 0; j--) {
            int x = a[j], y = a[j-1];
            if(x > y) swap(x,y);
            if((a[i] >= x && a[i] <= y) || (a[i] - 1 >= x && a[i] - 1 <= y) || (a[i] + 1 >= x && a[i] + 1 <= y)) {
                ans = min(ans, i - j); 
                break;
            }
        }
        for(int j = i + 1; j < n - 1; j++) {
            int x = a[j], y = a[j+1];
            if(x > y) swap(x,y);
            if((a[i] >= x && a[i] <= y) || (a[i] - 1 >= x && a[i] - 1 <= y) || (a[i] + 1 >= x && a[i] + 1 <= y)) {
                ans = min(ans, j - i); 
                break;
            }

        }
    }
    cout << (ans == INF ? -1 : ans) << nl;
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

