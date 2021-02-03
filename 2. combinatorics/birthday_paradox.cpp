#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;

#define ll long long
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    float n = 365;
    int i = 365;

    float frac = 1.0;
    int people = 0;
    float prob = 0.5;
    while(frac > prob){
        frac =  frac*(i/n);
        i--;
        people++;
    }

    cout<<(1-frac)*100<<endl;
    cout<<people<<endl;



    return 0;
}