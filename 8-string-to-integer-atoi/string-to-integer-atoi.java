class Solution {
    public int myAtoi(String s) {
        s = s.trim();
        if(s.length() == 0)
        {
            return 0;
        }

        boolean neg = false;
        long ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            char ch = s.charAt(i);

            if(i == 0)
            {
                if(ch == '-')
                {
                    neg = true;
                    continue;
                }
                else if(ch == '+')
                {
                    neg = false;
                    continue;
                }
            }

            if(ch >= '0' && ch <= '9')
            {
                int dig = ch - '0';
                ans = ans*10 + dig;

                if (!neg && ans > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                }
                if (neg && -ans < Integer.MIN_VALUE) {
                    return Integer.MIN_VALUE;
                }
            }
            else{
                break;
            }
        }
        
        if(neg)
        {
            return (int)(-ans);
        }
        else
        {
            return (int)ans;
        }
    }
}