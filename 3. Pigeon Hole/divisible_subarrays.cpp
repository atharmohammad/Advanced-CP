#include<iostream>
using namespace std;
#define ll long long 
int main(){

    ll int t;
    cin>>t;

    while(t--){

        ll int n;
        cin>>n;

        ll int x;
        ll int pre[n] = {0};
        pre[0] = 1;
        ll sum = 0;
        for(ll int i = 0 ; i<n ; i++){
            cin>>x;
            sum += x;
            sum = (sum%n + x)%n;
            pre[sum]++;
        }

        ll int ans = 0;
        for(ll int i = 0 ; i<n ; i++){
            ll int m = pre[i];
            ans += m*(m-1)/2;
        }

        cout<<ans<<endl;
    }

}