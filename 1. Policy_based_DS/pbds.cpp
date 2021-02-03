#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> pbds;

#define ll long long
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pbds st;
    st.insert({1,0}); // here i take pairs so change the type in the typdef
    st.insert({8,1});
    st.insert({8,2});
    st.insert({8,3});
    st.insert({9,1});
    
    for(int i = 0 ; i<st.size() ; i++){
        cout<<i<<" "<<st.find_by_order(i)->first<<" "<<st.find_by_order(i)->second;  
        cout<<endl;
    }

    cout<<st.order_of_key({4,2});



    return 0;
}