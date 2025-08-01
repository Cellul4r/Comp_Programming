#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    deque<int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a.push_back(x);
    }
    bool f = 1;
    for(int i = 0; i < k; i++) {
        if(f) {
            a.pop_front();
        } else {
            a.pop_back();
        }

        f = !f;
    }
    if(!f) {
        reverse(a.begin(), a.end());
    }
    for(auto &x : a) {
        cout<<x << " ";
    }
    return 0;
}
