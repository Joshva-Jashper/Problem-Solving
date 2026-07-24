class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique_set(nums.begin(),nums.end());
        vector<int> unique_nums(unique_set.begin(),unique_set.end());
        int n = unique_nums.size();

        unordered_set<int> pair;

        for (int i=0;i<n;i++)
        {
            for (int j=i;j<n;j++)
            {
                pair.insert(unique_nums[i]^unique_nums[j]);
            }
        }
        unordered_set<int> tri;
        for (auto it:pair)
        {
            for (auto el : unique_nums)
            {
                tri.insert(it^el);
            }
        }
        return tri.size();
    }
};