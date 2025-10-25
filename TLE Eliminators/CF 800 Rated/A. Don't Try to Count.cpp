#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s; 
        
        int operation = 0;
        
        while(x.find(s) == string::npos && operation < 5) {
            x += x;
            operation++;
        }
        if(x.find(s) != string::npos) {
            cout << operation << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
