#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;
        
        // Check impossible cases
        if(x == 1 && k == 1) {
            cout << "NO" << endl;
            continue;
        }
        
        if(x == 1 && k == 2 && n % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        
        // Build solution
        cout << "YES" << endl;
        vector<int> result;
        
        if(x != 1) {
            // Easy case: use all 1s
            result.assign(n, 1);
        } else {
            // x = 1, can't use 1
            if(n % 2 == 0) {
                // Use all 2s
                int count = n / 2;
                result.assign(count, 2);
            } else {
                // Use one 3, rest 2s
                result.push_back(3);
                int count = (n - 3) / 2;
                for(int i = 0; i < count; i++) {
                    result.push_back(2);
                }
            }
        }
        
        cout << result.size() << endl;
        for(int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
