#include <bits/stdc++.h>
using namespace std;

int main()
{   
        int n;
        cin>>n;
        vector<int> arr(n);

        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            cin>>arr[i];   
        }
        for(int x:arr){
            mini = min(mini,abs(x));
        }

        cout<<mini<<endl;


    return 0;
}
