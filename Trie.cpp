struct Node{
   vector<Node*> child;
    int cnt;
    Node(){
        cnt = 0;
        child.resize(26,NULL);
    }
};
struct Trie{
     Trie(){
         root = new Node();
      }
    void InsertString(const string& s){
         InsertString(root,0,s);
    }
    int QueryPrefix(const string& s){
         return QueryPrefix(root,0,s);
    }
    
    private:
    
    void InsertString(Node* root,int ind,const string& s){
          if(ind == s.length()) return ;
         int child_ind = s[ind]-'a';
        if(root-> child[child_ind]==NULL ) root-> child[child_ind] = new Node();
        root -> child[child_ind] -> cnt++;
        return InsertString(root-> child[child_ind],ind+1,s);
     }
    int QueryPrefix(Node* root ,int ind,const string&  s){
         if(root==NULL) return 0;
        if(ind==s.length()) return root -> cnt;
        return (root -> cnt + QueryPrefix(root-> child[s[ind]-'a'],ind+1,s));
    }
    Node* root;
};
