class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int good = 0;
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if (grid[i][j] == 1) {
                    good++;
                }
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        int minutes = 0;

        while (!q.empty() && good > 0) {
            int size = q.size();
            minutes++;

            for (int a = 0; a < size; a++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x < 0 || y < 0 || x >= n || y >= m) {
                        continue;
                    }

                    if (grid[x][y] != 1) {
                        continue;
                    }

                    grid[x][y] = 2;
                    good--;
                    q.push({x,y});
                }
            }
        }

        if (good == 0) {
            return minutes;
        }

        return -1;
    }
};