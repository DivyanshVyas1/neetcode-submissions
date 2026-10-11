class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid, int& area){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        if(grid[i][j]==1){
            grid[i][j]=0;
        }
        area++;
        dfs(i+1,j,grid,area);
        dfs(i-1,j,grid,area);
        dfs(i,j+1,grid,area);
        dfs(i,j-1,grid,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,area);
                    ans=max(area,ans);
                    area=0;
                }
            }
        }
        return ans;
    }
};