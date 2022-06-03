class prioritize {
public: 
    bool operator ()(int &p1 , int &p2) {
        return p1 > p2;
    }
};
 // syntax for calling
  priority_queue<int,vector<int>,prioritize> pq;
