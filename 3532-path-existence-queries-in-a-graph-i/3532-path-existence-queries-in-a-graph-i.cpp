class DSU 
{
    private:
        vector<int> size,parent;

    public:
        DSU(int n)
        {
            size.resize(n+1,1);
            parent.resize(n+1);
            for (int i=0;i<=n;i++)
                parent[i]=i;
        }

        int findParent(int node)
        {
            if(node == parent[node])
                return node;

            return parent[node]=findParent(parent[node]);    
        }

        void joinNode(int u,int v)
        {
            int up = findParent(u);
            int vp = findParent(v);

            if(up==vp)
                return;

            if(size[up]<size[vp])
            {
                parent[up]=vp;
                size[vp]+=size[up];
            }  
            else
            {
                parent[vp]=up;
                size[up]+=size[vp];
            }  
        }

};




class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        DSU ds(n);

        for (int i=1;i<n;i++)
        {
            if((nums[i]-nums[i-1])<=maxDiff)
            {
                ds.joinNode(i,i-1);
            }
        }

        vector<bool> res;

        for (auto x:queries)
        {
            if(ds.findParent(x[0])==ds.findParent(x[1]))
                res.push_back(true);
            else res.push_back(false);    
        }
        return res;
    }
};