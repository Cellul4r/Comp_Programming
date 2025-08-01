#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin>>n) {
        if(n == 0) break;
        vector<int> a(n);
        for(auto &x : a) {
            cin>>x;
        }
        int curr = 300, ans = 0;
        for(auto &x : a) {
            if(x <= curr) {
                curr -= x;
                ans += x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
