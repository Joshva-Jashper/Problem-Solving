class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        int t=0;
        for (int i=0;i<tickets.size();i++)
            q.push({tickets[i],i});
        
        while(!q.empty())
        {
            auto[node,y] = q.front();
            node -= 1;
            t+=1;
            q.pop();
            if(k==y && node ==0)
                return t;
            if(node!=0)
                q.push({node,y});

        }
        return -1;
    }
};