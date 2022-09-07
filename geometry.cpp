struct Line {
    int a, b;
    Line(int m, int c) {
        a = m;
        b = c;
    }
    int value(int x) {
        return a * x + b;
    }
};
 
struct CHull {
    vector<Line> hull;
    
    void addLine(Line c) {
        while (hull.size() >= 2) {
            Line a = hull[hull.size()-2];
            Line b = hull.back();
            // if (xinter(a, b) >= xinter(b, c)) {
            __int128 l = (b.b - a.b);
            __int128 m = b.a - c.a;
            __int128 e = (c.b - b.b);
            __int128 f = a.a - b.a;
            if (l * m >= e * f) {
                hull.pop_back();
            }
            else {
                break;
            }
        }
        hull.push_back(c);
    }
    
    int query(int x) {
        
        int low = 0;
        int high = hull.size() - 1;
        
        while (low < high) {
            int mid = (low + high) / 2;
            int v1 = hull[mid].value(x);
            int v2 = hull[mid+1].value(x);
            if (v1 < v2) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return hull[low].value(x);
        
    }
    
};
