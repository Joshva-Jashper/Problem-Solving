class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> vis(n,vector<int>(m,-1));

        pq.push({grid[0][0],{0,0}});

        vector<int> deltaCol = {-1,0,1,0};
        vector<int> deltaRow = {0,1,0,-1};

        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();

            int wt = el.first;
            int x = el.second.first;
            int y = el.second.second;
            if(vis[x][y]==0)
                continue;
            if(x==n-1 && y==m-1)
                return wt;

            vis[x][y]=0;

            for (int i=0;i<4;i++)
            {
                int nx = x+deltaRow[i];
                int ny = y+ deltaCol[i];

                if(nx < 0 || nx >= n || ny <0 || ny >=m || vis[nx][ny]==0)
                    continue;
                pq.push({max(wt,grid[nx][ny]),{nx,ny}});    
            }
        }
        return 0;
    }
};