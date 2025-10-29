#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        long long a,b,c;
        cin >>a>>b>>c;
        
        long long anna = a + (c + 1) / 2;
        long long katie= b + c / 2;       
        
        if(anna> katie) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
    
    return 0;
}
