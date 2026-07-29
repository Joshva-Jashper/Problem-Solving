class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mpp;

        int n = arr.size();

        for (int i=0;i<n;i++)
        {
            mpp[arr[i]]=i;
        }

        for (int i=0;i<n;i++)
        {
            
            if(mpp.find(arr[i]*2)!=mpp.end()&& mpp[arr[i]*2]!=i)
            {
               
                return true;
            }
            if(arr[i]%2==0 && mpp.find((arr[i]/(double)2.0))!=mpp.end()&&mpp[arr[i]/(double)2]!=i)
            {
                return true;
            }
        }

        return false;

    }
};