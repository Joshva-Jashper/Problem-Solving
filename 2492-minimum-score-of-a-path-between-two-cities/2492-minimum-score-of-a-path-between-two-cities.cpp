class disJoinSize
{
    public:
        vector<int> parent,size;

        disJoinSize(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
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

            else if(size[up]< size[vp])
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
    int minScore(int n, vector<vector<int>>& roads) {
        disJoinSize ds(n);
        for (auto edge : roads)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            ds.joinNode(u,v);
        }
        int parent = ds.findParent(1);

        int min_score = INT_MAX;
        for (auto edge : roads)
        {
            int par = ds.findParent(edge[0]);
            if(par == parent)
            {
                min_score = min(min_score,edge[2]);
            }
        }

        return min_score;
    }
};