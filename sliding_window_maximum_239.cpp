class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1)return nums;
        int max=INT_MIN;
        int index=-1;
        vector <int> ans;
        deque <int> track;
        for(int i=0;i<k;i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
                index=i;
            }
        }
        //cout<<index<<endl;
        ans.push_back(nums[index]);
        track.push_back(index);index++;
        while(index<k)
        {
            if(nums[track.back()]>=nums[index])
            {
                track.push_back(index);
            }
            else
            {
                while(!track.empty() && nums[track.back()] < nums[index] )
                {
                    track.pop_back();
                }
                track.push_back(index);
            }
            index++;

        }
        
        for(int i=k;i<nums.size();i++)
        {
            while(!track.empty() && track.front() <= i-k)
            {
                track.pop_front();
            }
            if(nums[track.back()]>=nums[i])
            {
                track.push_back(i);
            }
            else
            {
                while(!track.empty() && nums[track.back()] < nums[i] )
                {
                    track.pop_back();
                }
                track.push_back(i);
            }
            
            ans.push_back(nums[track.front()]);
        }
        //cout<<ans.size();
        return ans;
    }
};