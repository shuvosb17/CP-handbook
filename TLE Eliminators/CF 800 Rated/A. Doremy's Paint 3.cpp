#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>arr(n);

        for(int j=0;j<n;j++){
            cin>>arr[j];
        }

        map<int,int>freq;
        for(int x : arr){
            freq[x]++;
        }

        if(freq.size()==1){
            cout<<"Yes"<<endl;
        }
        else if(freq.size()==2){
            auto it= freq.begin();
            int count1=it->second;
            it++;
            int count2=it->second;


            if(abs(count1-count2)<=1){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
