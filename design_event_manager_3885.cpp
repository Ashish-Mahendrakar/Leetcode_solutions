class compare{
    public :
        bool operator()(pair<int,int> a,pair<int,int> b)
    {
        if(a.second == b.second)
        {
            return a.first > b.first;
        }

        return a.second < b.second;
    }
};

class EventManager {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    unordered_map <int,int> updated;
    EventManager(vector<vector<int>>& events) {
        for(auto v : events)
            {
                pair <int,int> temp;
                temp.first=v[0];
                temp.second=v[1];
                this->pq.push(temp);
            }
    }
    
    void updatePriority(int eventId, int newPriority) {
        
        pair <int,int> temp;
        temp.first=eventId;
        temp.second=newPriority;
        this->pq.push(temp);
        this->updated[eventId]=newPriority;
        
    }
    
    int pollHighest() {
        while(!this->pq.empty() && (updated.find(this->pq.top().first) != updated.end()) && ((updated[this->pq.top().first] == -1) || (updated[this->pq.top().first] != this->pq.top().second )))
            {
                pq.pop();
            }


        
        if(this->pq.empty())
        {
            return -1;
        }

        if(updated.find(this->pq.top().first) != updated.end())
        {
            this->updated[this->pq.top().first]=-1;
        }
        pair<int,int> top=this->pq.top();
        pq.pop();
        return top.first;

        
        
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */