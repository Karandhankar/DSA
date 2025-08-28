class Solution {
    public int longestSubarray(int[] nums) {
        int zerocount = 0;
        int maxlength = 0;

        int n = nums.length;

        int i=0;
        for(int j =0; j<n; j++)
        {
            if(nums[j]==0)
            zerocount += 1;

            while(zerocount > 1)
            {
                if(nums[i] == 0)
                zerocount--;

                i++;

            }

            maxlength = Math.max(maxlength, j-i);
        }
        return maxlength;
    }
}