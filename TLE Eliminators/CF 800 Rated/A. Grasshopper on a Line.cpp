#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        if(x%k!=0){
            cout<<"1"<<endl<<x<<endl;
            continue;
        }
        else{
            vector<int> arr;
            //k++;
            if(x%k==0){
                arr.push_back(1);
                int sum = x - 1;
                arr.push_back(sum);
                cout<<arr.size()<<endl;
                for(auto it:arr){
                    cout<< it << " ";
                }
            }
            else{
                arr.push_back(1);
                int sum = x / k; 
                for(int i=0;i < sum; i++){
                    arr.push_back(sum);
                }
                cout<<arr.size()<<endl;
                for(auto it:arr){
                    cout<< it << " ";
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
