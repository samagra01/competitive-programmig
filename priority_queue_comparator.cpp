class prioritize{
    public: bool operator ()(pii &p1, pii &p2){
         return p1.ss> p2.ss;
    }
};
