

bool check(ll mid,vi &v){
    
}
    ll hi = ; // max possible value;
    ll lo = ; // min possible value;
    ll ans = ; // default answer
   
   while(hi>=lo){
     ll mid = lo + (hi-lo)/2;
     if(check(mid,v)){
         hi = mid - 1;
         ans = mid;
     }else{
         lo = mid + 1;
     }
   }
   cout << ans << endl;
