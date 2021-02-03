#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    int t;
    cin>>t;

    while(t--){

        ll int n;
        cin>>n;

        ll int a[n];
        ll int sum = 0 ;
        ll int pre[n];
        for(int i = 0 ; i<n ; i++){
            cin>>a[i];
            sum += a[i];
            sum = (sum%n + a[i])%n;
            pre[i] = sum;
        }

        ll int frq[n]={0};

        for(int i = 0 ; i<n ; i++){
            frq[pre[i]]++;
        }

        if(frq[0] > 1){
            cout<<"-1"<<endl;
            continue;
        }
        int index = 0;
        int num ;
        int count;
        for(int i = 0 ; i<n ; i++){
            if(frq[pre[i]] > 1){
                index = i;
                count = frq[pre[i]] - 1;
                num = pre[i];
                break;
            }
        }
        vector<int>v;
        for(int j = index+1 ; j<n ; j++){
            if(count == 0)
                break;

            if(pre[j] == num)
                count--;

            v.push_back(j + 1);
        }

        cout<<v.size()<<endl;
        for(auto temp:v)
            cout<<temp<<" ";

        cout<<endl;

    }

}