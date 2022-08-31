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
// one important greedy approach for  problems 
ll get_min_cost_for_number(ll A, ll X) {
    // finding minimum cost // 
	for (ll digit = 32; digit >= 0; digit--) {
		if (!(X & ((ll)1 << digit))) {
			// checking if can on a particular bit 
			ll X_tmp = X;
			for (ll dd = digit - 1; dd >= 0; dd--) {
				X_tmp |= (ll)1 << dd;
			}
			if (X_tmp < A) {
				X |= (ll)1 << digit;
			}
		}
	}
	// i think this is any imp greedy approach // 

	return X - A;
}
