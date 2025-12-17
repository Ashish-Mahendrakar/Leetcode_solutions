class MinStack {
public:
    int *arr;
    int *min;
    int t=-1;
    MinStack() {
       arr=new int[30000];
       min=new int[30000]; 
    }
    
    void push(int val) {
        t++;
        arr[t]=val;
        if(t==0)
        {
            min[t]=val;
        }
        else
        {
            if(min[t-1]>val)
            {
                min[t]=val;
            }
            else
            {
                min[t]=min[t-1];
            }
        }
    }
    
    void pop() {
        min[t]=0;
        t--;
        
    }
    
    int top() {
        return arr[t];
    }
    
    int getMin() {
        return min[t];
    }
};