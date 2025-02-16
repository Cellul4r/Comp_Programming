#include<iostream>
using namespace std;

int main() {
    
    int n;
    cin>>n;
    unsigned long long a = 1, b = 1;
    for(int i = 3; i <= n;i++) {
        unsigned long long c = a + b;
        a = b;
        b = c;
    }
    cout << b;
    return 0;
}
