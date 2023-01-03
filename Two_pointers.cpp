//  so  condition for two pointers is :- 
//    L < L1
//    R <= R1
//  see if u can apply b.s. at any starting point is there a max. 


// DS for two pointers condition checking //  <<L< THIS METHOD IF FOR ZERO BASED INDEXING >>>
   ll zero_ct = 0;
   // pointers
   ll head = -1,tail = 0;
   ll ans = 0;
   while(tail<n){
    // while there is a next element to take and we will not voilate any condition//
        while(head+1<n && (v[head+1]==1 || (v[head+1]==0 && zero_ct<k))){
              head++;
              if(v[head]==0)zero_ct++;
        }
        // update the ans //
        ans = max(ans,head-tail+1);
        // move tail ahead //
        if(head>=tail){
            if(v[tail]==0) zero_ct--;
            tail++;
        }else{
            tail++;
            head = tail -1;
        }
   }
   cout << ans << endl;
// without comments

   ll zero_ct = 0;
   
   ll head = -1,tail = 0;
   ll ans = 0;
   while(tail<n){
  
        while(head+1<n && (v[head+1]==1 || (v[head+1]==0 && zero_ct<k))){
              head++;
              if(v[head]==0)zero_ct++;
        }
       
        ans = max(ans,head-tail+1);
       
        if(head>=tail){
            if(v[tail]==0) zero_ct--;
            tail++;
        }else{
            tail++;
            head = tail -1;
        }
   }
   cout << ans << endl;

