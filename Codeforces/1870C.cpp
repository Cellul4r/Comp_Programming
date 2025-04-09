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

void show(vector<int>& a, int n) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << min(a[i],a[j]) << " ";
        }
        cout << nl;
    }
}
void solve(){
    
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(auto &x : a) cin>>x;
    //show(a,n);
    vector<int> ord(n);
    for(int i = 0; i < n; i++) {
        ord[i] = i;
    }

    sort(all(ord), [&](int i, int j) {
        if(a[i] != a[j]) {
            return a[i] < a[j];
        }
        return i < j;
    });

    vector<int> ans(k+1);
    int max_ = ord[n-1];
    int min_ = ord[n-1];
    for(int i = n - 1; i >= 0; i--) {
        int j = i;
        while(j >= 0 && a[ord[j]] == a[ord[i]]) {
            min_ = min(min_, ord[j]);
            max_ = max(max_, ord[j]);
            j--;
        }
        j++;
        //cerr << ord[i] << " " << min_ << " " << max_ << j << nl;
        ans[a[ord[i]]] = 2 * (max_ - min_ + 1); 
        i = j;
    }

    for(int i = 1; i <= k; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
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

