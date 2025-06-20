class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Min heap
        priority_queue<int, vector<int>, greater<int>>pq;

        //k elements ko insert karo

        for(int i=0; i<k; i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k; i<nums.size(); i++)
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
        
    }
};