class node{
public:
    char data;
    int count;
    node(int data,int count)
    {
        this->data=data;
        this->count=count;
    }
};
class compare{
    public:
        bool operator()(node* a,node* b)
        {
            return a->count < b->count;
        }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node*,vector<node*>,compare>pq;
        if(a !=0)
           {node* na=new node('a',a);pq.push(na);} 
        if(b !=0)
           {node* nb=new node('b',b);pq.push(nb);} 
        if(c !=0)
           {node* nc=new node('c',c);pq.push(nc);} 
        

        //int total=a+b+c;
        int cur=0;
        string ans;
        
        while(!pq.empty())
        {
           node* first=pq.top();pq.pop();
           if(pq.empty())
           {
            
            pq.push(first);
            break;
           }
           else
           {
            node* sec=pq.top();
            pq.pop();
            if(first->count>=2)
            {
                ans.push_back(first->data);
                ans.push_back(first->data);
                ans.push_back(sec->data);
                if(sec->count >=2 && (first->count - sec->count ==1))
                {
                   ans.push_back(sec->data);
                   sec->count-=1; 
                }
                first->count-=2;
                sec->count-=1;
                if(first->count >0)
                {
                    pq.push(first);
                }

                if(sec->count >0)
                {
                    pq.push(sec);
                }

            }
            else
            {
                ans.push_back(first->data);
                ans.push_back(sec->data);
                first->count-=1;
                sec->count-=1;
                if(first->count >0)
                {
                    pq.push(first);
                }

                if(sec->count >0)
                {
                    pq.push(sec);
                }
            }
           }

        }

        cout<<pq.size();
        if((pq.size()==1) && (!ans.empty() && ans.back() != pq.top()->data))
        {
            if(pq.top()->count >=2)
            {
                ans.push_back(pq.top()->data);
                ans.push_back(pq.top()->data);
            }
            else
            {
                ans.push_back(pq.top()->data);
            }
        }
        else if(ans.empty() && pq.size()==1)
        {
            if(pq.top()->count >=2)
            {
                ans.push_back(pq.top()->data);
                ans.push_back(pq.top()->data);
            }
            else
            {
                ans.push_back(pq.top()->data);
            }
        }
        return ans;
    }
};