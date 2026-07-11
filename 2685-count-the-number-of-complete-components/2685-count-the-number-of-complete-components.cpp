class DSU
{
    public:
    vector<int> parent,size,edgeCount;

    public:
        DSU(int n)
        {
            parent.resize(n);
            size.resize(n,1);
            edgeCount.resize(n,0);
            for (int i=0;i<n;i++) parent[i]=i;

        }

        int findParent(int node)
        {
            if(node == parent[node])
            {
                return node;
            }

            return parent[node]= findParent(parent[node]);
        }

        void joinNode(int u, int v)
        {
            int up = findParent(u);
            int vp = findParent(v);

            if(up==vp)
            {
                edgeCount[up]++;
                return;
            }    

            if(size[vp]<size[up])
            {
                edgeCount[up]+=edgeCount[vp]+1;
                parent[vp]=parent[up];
                size[up]+=size[vp];
            }  
            else
            {
                edgeCount[vp]+=edgeCount[up]+1;
                parent[up]=parent[vp];
                size[vp]+=size[up];
            }  
        }

};


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        for (auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            ds.joinNode(u,v);
        }

        int complete_components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i) {
                int V = ds.size[i];         
                int E = ds.edgeCount[i];   

                if (E == (V * (V - 1)) / 2) {
                    complete_components++;
                }
            }
        }

        return complete_components;

        
    }
};