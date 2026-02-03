class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }

    void insertatb(int x)
    {
        //cout<<st.size()<<endl;
        if(this->st.empty())
        {
            //cout<<"h"<<endl;
            this->st.push(x);
            return;
        }

        int temp=this->st.top();
        this->st.pop();
        insertatb(x);
        this->st.push(temp);

    }
    
    void push(int x) {
        insertatb(x);
    }
    
    int pop() {
        int temp=st.top();
        st.pop();
        return temp;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }

    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */