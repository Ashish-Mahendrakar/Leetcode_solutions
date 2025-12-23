class RecentCounter {
public:
    deque <int> timestamp;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int temp=t-3000;
        while(!timestamp.empty() && timestamp.front()<temp )
        {
            
            timestamp.pop_front();
        }
        timestamp.push_back(t);
        return timestamp.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */