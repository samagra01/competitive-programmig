void solve(){ 
    ll n; cin>>n;
    vector<ll> a(n);
    for(auto &it:a){
        cin>>it;
    }
    auto getv=[&](vector<ll> v){
        ll sum=0;
        for(auto it:v){
            sum+=it;
        }
        return sum;
    };
  // writting bruteforce function for bruteforcing 
    auto change=[&](vector<ll> &v,ll l,ll r){
        ll nax=0,nin=INF_ADD;
        for(ll i=l;i<=r;i++){
            nax=max(nax,v[i]);
            nin=min(nin,v[i]);
        }
        for(ll i=l;i<=r;i++){
            v[i]=nax-nin;
        } 
        return v;
    };
    if(n>=4){  
        sort(all(a));
        cout<<a.back()*n<<"\n";
    }
    else if(n==2){ 
        ll ans=max(getv(a),2*(abs(a[0]-a[1])));
        cout<<ans<<"\n";
    }
    else{
//       #################################  Here BRUTE_FORCE IS DONE ###########################################################################//
        vector<pair<ll,ll>> brute={{0,1},{0,1},{0,2},{1,2},{1,2}}; //we need to perform operation on (0,1) and (1,2) atmost twice
        ll ans=getv(a);
        do{
            vector<ll> v=a;
            for(auto cur:brute){
                change(v,cur.first,cur.second);
                ans=max(ans,getv(v));
            }
        }while(next_permutation(all(brute)));
        cout<<ans<<"\n";
    }
    return;                                
}  
