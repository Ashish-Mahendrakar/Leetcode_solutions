class compare {
public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;

        
        vector<long long> pre(m, 0);
        
        vector<long long> suf(m, 0);

        
        priority_queue<int> maxHeap; 
        long long sumLeft = 0;

        for (int i = 0; i < m; ++i) {
            sumLeft += nums[i];
            maxHeap.push(nums[i]);

            if ((int)maxHeap.size() > n) {
                sumLeft -= maxHeap.top();
                maxHeap.pop();
            }

            if ((int)maxHeap.size() == n) {
                pre[i] = sumLeft;
            } else {
                
                pre[i] = LLONG_MAX;
            }
        }

       
        priority_queue<int, vector<int>, compare> minHeap; 
        long long sumRight = 0;

        for (int i = m - 1; i >= 0; --i) {
            sumRight += nums[i];
            minHeap.push(nums[i]);

            if ((int)minHeap.size() > n) {
                sumRight -= minHeap.top();
                minHeap.pop();
            }

            if ((int)minHeap.size() == n) {
                suf[i] = sumRight;
            } else {
                suf[i] = LLONG_MIN;
            }
        }

        
        long long ans = LLONG_MAX;
        
        for (int i = n - 1; i < 2 * n; ++i) {
            if (pre[i] != LLONG_MAX && suf[i + 1] != LLONG_MIN) {
                ans = min(ans, pre[i] - suf[i + 1]);
            }
        }

        return ans;
    }
};
