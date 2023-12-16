#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define huree ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);


int main()
{
    huree
    freopen("1878C.inp", "r", stdin);
    freopen("1878C.ans", "w", stdout);
     ll t=1;
    cin>>t;
     while(t--)
     {
      //  cout<<"start";
      ll n,k,s;
      cin>>n>>k>>s;
      if(k > n )
      {
         cout<<"NO"<<endl;
         continue;
      }
       if(k * (k+1) /2 > s || (n-k+1+n)*k / 2 < s)
       {
          cout<<"NO"<<endl;
       }
       else{
          cout<<"YES"<<endl;
       }

     }
    return 0;


}
