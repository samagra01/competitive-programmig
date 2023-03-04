//  given a string s //       
for(int i=0;i<n;i++){
            if(s[i]=='('){
                curr+=1;
                last = '(';
            }else if(s[i]==')'){
                curr-=1;
                last = ')';
            }
            if(curr<0){
                k += abs(curr);
                // if(i+1<n and s[i+1]=='('){
                    curr = 0;
                // }
                
            }
        }
        if(curr>0){
             k += curr;
        }
