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
    vector<vector<int>> answer;
    for(auto &x : a) cin>>x;

    auto f = [&](int idx, int val) {
        return idx < (int)answer.size() && answer[idx].back() < val;
    };
    for(auto &x : a) {
        int l = 0, r = answer.size(); 
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(f(mid,x)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(f(l,x)) {
            answer[l].push_back(x);
        } else {
            answer.push_back(vector<int>{x});
        }
    }
    for(auto &x : answer) {
        for(auto &y : x) {
            cout << y << " ";
        }
        cout << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

