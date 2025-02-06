#include<bits/stdc++.h>
using namespace std;

string s;
bool recur(int i) {

    if(i == (int)s.size() / 2) {
        return true;
    }

    if(s[i] != s[(int)s.size() - i - 1]) {
        return false;
    }
    
    return recur(i+1);
}
void solve(){
    
    cin>>s;
    cout << (recur(0) ? "yes" : "no"); 

}

int main(){
    solve();
    return 0;
}

