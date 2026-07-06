class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int  len = intervals.size();
        vector<int> removed(len,-1);

        for (int i=0;i<len;i++)
        {
            if(removed[i]==0)
                continue;
            for (int j =0;j<len;j++)
            {
                if(i==j || removed[j]==0)
                    continue;
                if(intervals[j][0] <= intervals[i][0] && intervals[i][1]<=intervals[j][1])
                {
                    cout << intervals[i][0] <<" "<< intervals[i][1]<<endl;
                    removed[i]=0;
                    break;
                }
            }
        }

        int cnt =0;

        for (auto it: removed)
        {
            if(it==0)
                cnt++;
        }
        return len - cnt;
    }
};