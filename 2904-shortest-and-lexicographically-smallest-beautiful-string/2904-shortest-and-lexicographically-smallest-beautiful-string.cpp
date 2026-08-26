class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int ones_count = 0;

        int left = 0;
        for (int right = 0;right < s.size();right++)
        {
            if(s[right]=='1')
                ones_count++;

            while(ones_count==k)
            {
                while (s[left]=='0')
                    left++;

                string curr = s.substr(left,right-left+1);

                if(ans.empty() || ans.length() > curr.length() || (curr.length() == 
                    ans.length() && curr < ans))
                {
                    ans = curr;
                }
                ones_count--;
                left++;

            }


        }
        return ans;
        
    }
};