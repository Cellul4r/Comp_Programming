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

int pos(int n) {
    return (n + 1) / 2 - 1;
}
void solve(){
    
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    int med = a[0], p = pos(n);
    sort(all(a));
    if(a[p] == med) {
        cout << "YES" << nl;
        return;
    }

    int left,right;
    left = lower_bound(all(a), med) - a.begin();
    right = n - left - 1;
    if(left == p) {
        cout << "YES" << nl;
        return;
    } else if(left > p) {
        int cnt = lower_bound(all(a), -med) - a.begin();
        if(cnt >= left - p) {
            cout << "YES" << nl;
            return;
        }
    } else {
        // move the right to the left
        int cnt = n - (lower_bound(all(a), abs(med)) - a.begin());
        if(cnt >= p - left) {
            cout << "YES" << nl;
            return;
        }
    }

    for(auto &x : a) {
        if(x == med) {
            x = -x;
            break;
        }
    }

    med = -med;
    sort(all(a));
    if(a[p] == med) {
        cout << "YES" << nl;
        return;
    }

    left = lower_bound(all(a), med) - a.begin();
    right = n - left - 1;
    if(left == p) {
        cout << "YES" << nl;
        return;
    } else if(left > p) {
        int cnt = lower_bound(all(a), -med) - a.begin();
        if(cnt >= left - p) {
            cout << "YES" << nl;
            return;
        }
    } else {
        // move the right to the left
        int cnt = n - (lower_bound(all(a), abs(med)) - a.begin());
        if(cnt >= p - left) {
            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

