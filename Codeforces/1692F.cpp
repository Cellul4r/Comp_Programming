#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
void solve() {
        
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> save;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i] = a[i] % 10;
        save[a[i]]++;
    }
    for(int i=0;i<10;i++) {
        if(!save[i]) continue;
        for(int j=i;j<10;j++) {
            if(!save[j]) continue;
            if(i == j && save[i] < 2) continue;
            for(int k=j;k<10;k++) {
                if(!save[k]) continue;
                if(k == j && i == j && save[k] < 3) continue;
                if(k == j && save[k] < 2) continue;
                if((i + j + k) % 10 == 3) {
                    cout << "YES" << nl;
                    return;
                }
            }
        }
    }
    // 0 2 4 9
    cout << "NO" << nl;
    // digit 3
    // 0 0 3
    // 0 1 2
    // 0 4 9
    // 0 5 8
    // 0 6 7
    // 1 1 1
    // 1 3 9
    // 1 4 8
    // 1 5 7
    // 1 6 6
    // 2 2 9
    // 2 3 8
    // 2 4 7
    // 2 5 6
    // 3 3 7
    // 3 4 6
    // 3 5 5
    // 4 4 5
    
}
int main() {
	// your code goes here
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}
