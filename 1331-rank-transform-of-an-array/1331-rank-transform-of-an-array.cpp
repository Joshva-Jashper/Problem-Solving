class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        if(arr.size()==0)
            return {};

      
        int rank =1;
        unordered_map<int,int> mpp;

        for (int i=0;i<n;i++)
        {
            if(mpp.find(temp[i])==mpp.end())
            {
                mpp[temp[i]]=rank;
                
                rank++;
            }
        }

        vector<int> result(n);

        for (int i=0;i<n;i++)
        {
            result[i]=mpp[arr[i]];
        }
        return result;
    }
};