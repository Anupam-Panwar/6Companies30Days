class Solution
{
public:
    int bfs(vector<vector<int>> &grid, int xi, int yi)
    {
        int n = grid.size();
        int m = grid[0].size();
        int temp = 0;
        queue<pair<int, int>> qu;
        qu.push(make_pair(xi, yi));
        grid[xi][yi] = 2;

        while (qu.empty() == false)
        {
            temp++;
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            if (y - 1 >= 0 && grid[x][y - 1] == 1) // left
            {
                grid[x][y - 1] = 2;
                qu.push(make_pair(x, y - 1));
            }

            if (y + 1 < m && grid[x][y + 1] == 1) // right
            {
                grid[x][y + 1] = 2;
                qu.push(make_pair(x, y + 1));
            }

            if (x - 1 >= 0 && grid[x - 1][y] == 1) // top
            {
                grid[x - 1][y] = 2;
                qu.push(make_pair(x - 1, y));
            }

            if (x + 1 < n && grid[x + 1][y] == 1) // bottom
            {
                grid[x + 1][y] = 2;
                qu.push(make_pair(x + 1, y));
            }

            if (x - 1 >= 0 && y - 1 >= 0 && grid[x - 1][y - 1] == 1) // top left
            {
                grid[x - 1][y - 1] = 2;
                qu.push(make_pair(x - 1, y - 1));
            }

            if (x - 1 >= 0 && y + 1 < m && grid[x - 1][y + 1] == 1) // top right
            {
                grid[x - 1][y + 1] = 2;
                qu.push(make_pair(x - 1, y + 1));
            }

            if (x + 1 < n && y - 1 >= 0 && grid[x + 1][y - 1] == 1) // bottom left
            {
                grid[x + 1][y - 1] = 2;
                qu.push(make_pair(x + 1, y - 1));
            }

            if (x + 1 < n && y + 1 < m && grid[x + 1][y + 1] == 1) // bottom right
            {
                grid[x + 1][y + 1] = 2;
                qu.push(make_pair(x + 1, y + 1));
            }
        }
        return temp;
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int temp = bfs(grid, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};