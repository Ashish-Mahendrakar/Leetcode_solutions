class Info{
    public:
        int data;
        int row;
        int column;
        Info(int _data,int _row,int _column){
            this->data=_data;
            this->row=_row;
            this->column=_column;
        }
};
class compare1{
    public:
        bool operator()(Info* a,Info*b)
        {
            return a->data > b->data;
        }
};
class compare2{
    public:
        bool operator()(Info* a,Info*b)
        {
            return a->data < b->data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2, 0);  
        priority_queue <Info*, vector <Info*>, compare1> pq_min;
        priority_queue <Info*, vector <Info*>, compare2> pq_max;

        
        for(int i = 0; i < nums.size(); i++) {
            Info* temp = new Info(nums[i][0], i, 0);
            pq_min.push(temp);
            pq_max.push(temp);
        }

        
        ans[0] = pq_min.top()->data;
        ans[1] = pq_max.top()->data;

        while(!pq_min.empty()) {
            Info *temp = pq_min.top();

            
            if((pq_max.top()->data) - (pq_min.top()->data) < ans[1] - ans[0]) {
                ans[0] = pq_min.top()->data;
                ans[1] = pq_max.top()->data;
            }

            
            pq_min.pop();
            

            
            if(temp->column + 1 < nums[temp->row].size()) {
                Info* newn = new Info(nums[temp->row][temp->column + 1], temp->row, temp->column + 1);
                pq_min.push(newn);
                if(newn->data > pq_max.top()->data)
                   {
                      pq_max.pop();
                     }
                pq_max.push(newn);
            } 
            else
            {
                break;
            }
            
        }

        return ans;
    }
};