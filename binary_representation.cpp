vector<ll> Binary_representation(ll x){
      vector<ll>  ans;
      for(int i=30;i>=0;i--){
       if(x&(1<<i))ans.push_back(1);        
        else ans.push_back(0);
      }
    return ans;
}
// recurssive method
void printbin(unsigned int x)
{
    if(x>1)
    {
        printbin(x/2);    // recursive call to rest of the bits
    }
    cout<<(x%2);          // print the last bit
}
