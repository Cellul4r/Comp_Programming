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

void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    int min_ = 0, max_ = 0;
    // for maximum as possible we have to make that day show the log = "0"
    // for minimum as possible we just reverse from the lastday that has show
    if(a[0] > 0) {
        cout << -1;
        return;
    }

    a[0] = 0;
    for(int i = n-1; i >= 0; i--) {
        //cerr << i << nl;
        if(a[i] != -1) {
            if(i - a[i] < 0) {
                cout << -1;
                return;
            }
            for(int j = i - a[i]; j <= i; j++) {
                if(a[j] != -1 && a[j] != a[i] - i + j) {
                    cout << -1;
                    return;
                }
            }
            i -= a[i];
            min_++;
            max_++;
        } else {
            for(int j = i; j >= 0; j--) {
                if(a[j] == -1) max_++;
                else {
                    i = j + 1;
                    break;
                }
            }
        }
    }

    cout << min_ << " " << max_;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

