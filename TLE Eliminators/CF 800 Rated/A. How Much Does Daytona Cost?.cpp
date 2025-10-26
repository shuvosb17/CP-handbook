#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        map<int, int>freq;
        
         for(int x:arr){
            freq[x]++;
        }

        int check=0;

        for(auto[key,count] : freq){
            if(k==key){
                check++;
            }
        }
        if(check>=1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
