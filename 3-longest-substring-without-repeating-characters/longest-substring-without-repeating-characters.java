class Solution {
    public int lengthOfLongestSubstring(String s) {
        boolean []count = new boolean[256];

        int first = 0, second = 0, length = 0;

        while(second < s.length())
        {
            while(count[s.charAt(second)])
            {
                count[s.charAt(first)] = false;
                first++;

            }

            count[s.charAt(second)] = true;
            length = Math.max(length, second-first+1);
            second++;
        }

        return length;
    }
}