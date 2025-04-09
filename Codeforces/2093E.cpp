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


int n,k;
bool check(int x, vector<int>& a) {
    int partition = 0;
    set<int> save;
    int i = 0;
    while(i < n) {
        if(a[i] < x) {
            save.insert(a[i]);
            if((int)save.size() == x) {
                partition++;
                save.clear();
            }
        }
        i++;
    }
    return partition >= k;
}

void solve(){
    
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    if(n == 1) {
        cout << (a[0] == 0 ? 1 : 0) << nl;
        return;
    }
    // split to k subarrays

    int l = 1, r = 2e5+5;
    int ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid,a)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << nl;
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

