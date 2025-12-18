class StockSpanner {
public:
    int top;
    int* pricel;
    int* span;
    StockSpanner() {
        top=-1;
        pricel=new int[10000];
        span=new int[10000];
    }
    
    int next(int price) {
        if(top==-1)
        {
            top++;
            pricel[top]=price;
            span[top]=1;
        }
        else
        {
            if(price >= pricel[top])
            {
                top++;
                pricel[top]=price;
                int temp=top-1;
                while(temp>=0 && pricel[temp]<=price)
                {
                    temp--;
                }
                span[top]=top-temp;
            }
            else
            {
                top++;
                pricel[top]=price;
                span[top]=1;
            }
        }
        return span[top];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */