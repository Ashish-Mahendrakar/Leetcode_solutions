class comp{
    public:
        bool operator()(int &a,int &b)
        {
            return a>b;
        }
};
class KthLargest {
public:
    priority_queue <int,vector<int>,comp> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //cout<<"K"<<endl;
        this->k=k;
        //prority_queue <int,vector<int>,comp> q;
        while(this->q.size() < k  && !nums.empty())
        {
            this->q.push(nums.back());
            nums.pop_back();
        }
        //cout<<"K"<<endl;
        //cout<<q.size()<<" "<<nums.size()<<endl;

    }
    
    int add(int val) {
        

        if(this->q.size() == this->k)
        {
            if(this->q.top() >=  val)
            {
                return q.top();
            }
            else
            {
                q.pop();
                q.push(val);
                return q.top();
            }
        }
        else
        {
            q.push(val);
            return q.top();
        }

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */