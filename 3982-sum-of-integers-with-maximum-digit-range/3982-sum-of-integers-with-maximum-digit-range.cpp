class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,int> mpp;

        int max_all =0;

        for (auto it : nums)
        {
            int max_digit = INT_MIN;
            int min_digit = INT_MAX;

            int num = it;

            while(it > 0)
            {
                int d = it%10;
                max_digit = max(max_digit,d);
                min_digit = min(min_digit,d);

                it = it /10;
            }
            int k = max_digit - min_digit;

            max_all = max(max_all,k);
            mpp[num]=k;

        }
        int sum = 0;

        for (auto [x,y] : mpp)
        {
            if(y==max_all)
            {
                sum+=x;
            }
        }

        return sum;
    }
};