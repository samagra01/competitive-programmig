 string reverseWords(string s) {
        stringstream ss(s);
        string ans,temp;
        while(getline(ss,temp,' ')){
           reverse(temp.begin(),temp.end());
            // cout << temp << " " ;
            ans += (temp + ' ');
        
        }
        // cout << endl;
        return ans.substr(0,ans.size()-1);
    }
// In this we break the stream at some char we want //
whlie(cin>>n)
  // if we dont know the amount of input //
  while(ss>>word)
    // for breaking a string on spaces // 

