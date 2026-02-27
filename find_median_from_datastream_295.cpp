class compmin{
    public:
        bool operator()(int a,int b)
        {
            return a>b;
        }
};

class compmax{
    public:
        bool operator()(int a,int b)
        {
            return a<b;
        }
};
class MedianFinder {
public:
    priority_queue<int,vector<int>,compmin> pqmin;
    priority_queue<int,vector<int>,compmax> pqmax;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqmax.size() == pqmin.size())
        {
            if(pqmax.empty())
            {
                pqmax.push(num);
            }
            else if(pqmax.top()>=num || num <= pqmin.top())
            {
                //cout<<pqmax.top()<<endl;
                pqmax.push(num);
            }
            else
            {
                
                int temp=pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(num);
                //cout<<temp<<" "<<num<<endl;
            }
        }
        else
        {
            if(pqmax.top()<=num)
            {
                pqmin.push(num);
            }
            else
            {
                int temp=pqmax.top();
                pqmax.pop();
                pqmax.push(num);
                pqmin.push(temp);
            }
        }
        if(!pqmin.empty() && !pqmax.empty())
            cout<<pqmax.size()<<" "<<pqmin.size()<<" "<<pqmax.top()<<" "<<pqmin.top()<<endl;
    }
    
    double findMedian() {
        double b=pqmax.top();
        //cout<<b<<endl;
        if(pqmin.size() == pqmax.size())
        {
            double a=pqmin.top();
            
            return (a+b)/2;
        }
        else
        {
            return b;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */