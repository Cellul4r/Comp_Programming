#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define L long
#define sLL signed long long
#define uLL unsigned long long
#define f first 
#define pf printf
#define sf scanf
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e5;

struct seg {

    ld x;
    ll m;
    ll b;
};

vector<seg> hull;
void insert(ll m,ll b) {
    while(hull.size()) {
        seg s = hull.back();
        if(s.b + s.m * s.x > b + m * s.x) {
            if(s.m - m) hull.push_back({(b - s.b) / (ld)(s.m - m), m, b});
            return;
        }

        hull.pop_back();
    }
    hull = {{LLONG_MIN, m, b}};
}

ll query(ll x) {
    seg ss = *--upper_bound(hull.begin(),hull.end(), x, [](ll a,seg b) {return a < b.x;});
    return x * ss.m + ss.b;
}

struct rect { 

    ll x,y;
    ll a;

};

bool comp(const rect& lhs, const rect& rhs) {

    return lhs.x < rhs.x;
}
void solve() {
    
    int n;
    cin>>n;
    rect rt[n];
    for(int i=0;i<n;++i) {
        cin>>rt[i].x >> rt[i].y >> rt[i].a;
    }

    sort(rt,rt+n, comp);

    for(int i=0;i<n;++i) {
        auto r = rt[i];
    }
    insert(0,0);
    ll ans = 0;

    for(int i=0;i<n;++i) {

        ll k = rt[i].x * rt[i].y - rt[i].a + query(-rt[i].y);
        ans = max(ans,k);
        insert(rt[i].x, k);
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}

