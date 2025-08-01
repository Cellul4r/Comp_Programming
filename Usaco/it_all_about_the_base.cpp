/*
 *   author : cellul4r
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

// Check if all digits in n are valid for base b
bool valid_digits(ll n, int b) {
    while (n) {
        if (n % 10 >= b) return false;
        n /= 10;
    }
    return true;
}

// Convert a number (given in decimal form but actually in base b) to base 10
ll base10(int b, ll n) {
    ll now = 1;
    ll res = 0;
    while (n != 0) {
        res += now * (n % 10); 
        now *= 1LL * b;
        n /= 10;
    }
    return res;
}

ll a, b;

// Try to find a base y for b such that base10(x, a) == base10(y, b)
ll check(ll x) {
    if (!valid_digits(a, x)) return -1;
    ll k = base10(x, a);
    
    ll l = 10, r = 15000;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (!valid_digits(b, mid)) {
            r = mid - 1;
            continue;
        }
        ll now = base10(mid, b);
        if (now == k) return mid;
        else if (now < k) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void solve() {
    cin >> a >> b;
    for (ll x = 10; x <= 15000; x++) {
        ll y = check(x);
        if (y != -1) {
            cout << x << " " << y << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "whatbase";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

