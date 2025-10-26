#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum =0;
        for(int i=0;i<n-1;i++){
            int a;
            cin>>a;
            sum = sum + a;
        }
            if(sum<=0){
                int final= (-1) * sum;
                cout<<final<<endl;;
            }
            else if(sum>0){
                int final= (-1) * sum;
                cout<<final<<endl;
            }

    }

    return 0;
}
