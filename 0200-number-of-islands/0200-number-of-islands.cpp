class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        queue<pair<int, int>> q;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {

                if(grid[i][j] == '1') {
                    
                    count++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while(!q.empty()) {
                        
                        auto [x, y] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            
                            int nx = x + dr[k];
                            int ny = y + dc[k];

                            if(nx >= 0 && nx < r &&
                               ny >= 0 && ny < c &&
                               grid[nx][ny] == '1') {
                                
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};