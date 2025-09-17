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
    
    int n,x;
    string s; cin>>n>>x>>s;
    x--;
    // he is on the bound
    if(x == 0 || x == n - 1) {
        cout << 1 << nl;
        return;
    }

    // if wall is n - 2 cells then mani can only placed 1 possible way.
    // then hamid will always go through the wall until on the bound
    // or there are no walls then he can go any direction mani can not 
    int wall = 0;
    for(auto &k : s) {
        if(k == '#') wall++;
    }
    if(wall == n - 1 || wall == 0) {
        cout << 1 << nl;
        return;
    }
    int ans = 0;
    // go left
    vector<int> left, right;
    vector<int> pre(n+1);
    for(int i = 0; i < n; i++) {
        pre[i+1] = pre[i];
        if(s[i] == '#') {
            pre[i+1]++;
        }
    }
    for(int i = 0; i < x; i++) {
        if(s[i] == '#') left.push_back(i);
    }
    for(int i = n - 1; i > x; i--) {
        if(s[i] == '#') right.push_back(i);
    }
    while(x != 0 && x != n - 1) {
        //cout << x << nl;
        // place wall
        if(left.empty()) {
            if(pre[x-1] - pre[0] < x) {
                left.push_back(0);
            }
        } else if(right.empty()) {
            if(pre[n] - pre[x] < n - x) {
                right.push_back(n);
            }
        } else if(left.back() == 0) {
            if(pre[x-1] - pre[0] < x) {
                left.push_back(0);
            }

        } else if(right.back() == 0) {
            if(pre[n] - pre[x] < n - x) {
                right.push_back(n);
            }

        } else if(left.size() < right.size()) {
            if(pre[x-1] - pre[0] < x) {
                left.push_back(0);
            }

        } else {
            if(pre[n] - pre[x] < n - x) {
                right.push_back(n);
            }
        }
        if(left.size() < right.size()) {
            if(left.empty()) x = 0;
            else {
                ans++;
                x = left.back();
                left.pop_back();
            }
        } else{
            if(right.empty()) x = 0;
            else {
                ans++;
                x = right.back();
                right.pop_back();
            }
        }
    }
    cout << ans + 1 << nl;
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

