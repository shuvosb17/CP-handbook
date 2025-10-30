#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int min = INT_MAX;
        int sum = 0;
        int op = 0;
        vector<int> arr(x);
        for(int i=0;i<x;i++){
            cin>>arr[i];
        }

        bool is_sorted= true;

        for(int i=0;i<x-1;i++){
            if(arr[i]>arr[i+1]){
                is_sorted= false;
                break;
            }
        }
        if(!is_sorted)
        {
            cout<<"0"<<endl;
        }
        
        else{
            for(int i = 0; i<x-1; i++){
            sum = abs(arr[i]-arr[i+1]);
            if(min>=sum){
                op = sum;
                min = sum;
            }
        }
        int final = (op/2) + 1;
        cout<<final<<endl;
        }
        
    }

    return 0;
}
