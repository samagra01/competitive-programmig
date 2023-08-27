class KMP {
private:
    vector<int> LPS(string s){
        vector<int> lps(s.size(),0);
        int j = 0;
        int i = 1;
        while(i < s.size()){
            if(s[i] == s[j]){
                j++;
                lps[i] = j;
                i++;
            }else{
                if(j == 0){
                    lps[i] = 0;
                    i++;
                }else{
                    j = lps[j-1];
                }
            }
        }
        return lps;
    }
public:
    int cnt_of_pattern(string pat,string text){
        string temp = pat + '#' + text;
        vector<int> lps = LPS(temp);
        int cnt = 0;
        for(auto it : lps){
            if(it == pat.size()){
                cnt++;
            }
        }
        return cnt;
    }
    void idx_of_occurances(string pat,string text){
        string temp = pat + '#' + text;
        vector<int> lps = LPS(temp);
        vector<int> idx;
        for(int i=0;i<lps.size();i++){
            if(lps[i] == pat.size()){
                idx.pb(i-(2*pat.size())+1);
            }
        }
        for(auto it : idx){
            cout<<it<<" ";
        }cout<<"\n";
    }
};

void solve(){
    KMP obj1;
    string pat = "aab";
    string text = "aabaabaabaab";
    cout<<obj1.cnt_of_pattern(pat,text)<<"\n";
    obj1.idx_of_occurances(pat,text);
}
