#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct segtree {

    vector<ll> t, lazy;

    void init(ll n) {
        t.resize(4*n+10, -1);
        lazy.resize(4*n+10, -1);
    }

    void propagate(ll node, ll l, ll r) {
        if(lazy[node] != -1) {
            t[node] = lazy[node];
            if(l != r) {
                lazy[node*2] = lazy[node];
                lazy[node*2+1] = lazy[node];
            }
            lazy[node] = -1;
        }
    }

    void rangeUpdate(ll node, ll l, ll r, ll qL, ll qR, ll v) {
        propagate(node, l, r);
        if(l > r || r < qL || l > qR) return;
        if(l >= qL && r <= qR) {
            lazy[node] = v;
            propagate(node, l, r);
            return;
        }
        ll mid = (l + r) / 2;
        rangeUpdate(node*2, l, mid, qL, qR, v);
        rangeUpdate(node*2+1, mid+1, r, qL, qR, v);
    }

    ll query(ll node, ll l, ll r, ll pos) {
        propagate(node, l, r);
        if(l == r) {
            return t[node];
        }
        ll mid = (l + r) / 2;
        if(pos <= mid) return query(node*2, l, mid, pos);
        return query(node*2+1, mid+1, r, pos);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n);

    vector<tuple<ll, ll, ll>> queries;
    for(int i = 0; i < m; ++i) {
        ll l, r, x;
        cin >> l >> r >> x;
        --l; --r; --x;
        queries.push_back({l, r, x});
    }

    reverse(queries.begin(), queries.end());

    for(auto [l, r, x] : queries) {
        if(l <= x-1) seg.rangeUpdate(1, 0, n-1, l, x-1, x+1); // Update range [l, x-1] with x+1
        if(x+1 <= r) seg.rangeUpdate(1, 0, n-1, x+1, r, x+1); // Update range [x+1, r] with x+1
    }

    for(int i = 0; i < n; ++i) {
        auto ans = seg.query(1, 0, n-1, i);
        cout << (ans == -1 ? 0 : ans) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
