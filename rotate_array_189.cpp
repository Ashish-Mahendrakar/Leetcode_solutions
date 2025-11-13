class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int len=nums.size();
       k=k%len;
       if(k==0)
       {
        return;
       }
       vector<int> temp(k,0);
       int i=0;
       int j=len-k;
       while(i<k && j<len)
       {
        temp[i]=nums[j];
        //cout<<temp[i]<<" "<<i<<" "<<j<<endl;
        i++;j++;
       }
      
       int end=len-1;
       i=len-k-1;
       while(end >=0 && i>=0)
       {
        nums[end]=nums[i];
        i--;end--;
       }
       i=0;
       while(i<k)
       {
        nums[i]=temp[i];
        i++;
       }
       
    }
};