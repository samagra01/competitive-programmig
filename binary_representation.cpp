vector<ll> Binary_representation(ll x){
      vector<ll>  ans;
      for(int i=30;i>=0;i--){
       if(x&(1<<i))ans.push_back(1);        
        else ans.push_back(0);
      }
    return ans;
}
