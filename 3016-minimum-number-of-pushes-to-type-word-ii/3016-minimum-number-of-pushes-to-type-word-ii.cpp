class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);

        for (auto it:word)
        {
            arr[it-'a']++;
        }
        sort(arr.rbegin(),arr.rend());

        long long sum =0;

        for (int i =0;i<26;i++)
        {
            if(arr[i]==0)
                continue;
            int mul = (i/8)+1;
            sum+=arr[i]*mul;    
        }
        return sum;

    }
};