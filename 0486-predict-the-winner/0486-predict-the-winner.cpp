class Solution {
public:


    int findmax(vector<int>&nums,int i,int j,bool p1)
    {
        if(i==j)
        {
            if(p1)
                return nums[i];
            return 0;    
        }
        if(p1)
        {
            int left = nums[i]+findmax(nums,i+1,j,false);
            int right = nums[j]+findmax(nums,i,j-1,false);
            return max(left,right);
        }
        else
        {
            int left = findmax(nums,i+1,j,true);
            int right = findmax(nums,i,j-1,true);
            return min(left,right);
        }
    }


    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int p1 = findmax(nums,0,n-1,true);
        int p2 = totalSum-p1;

        if(p1>=p2)
            return true;
        return false;            

    }
};