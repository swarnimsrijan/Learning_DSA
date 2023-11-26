#include <vector>

class Solution {
public:
    int solution(vector<vector<int>>& grid, int m, int n, int i, int j, int zeros) {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == -1) {
            return 0;
        }

        if (grid[i][j] == 2) {
            return zeros == 0 ? 1 : 0;
        }

        grid[i][j] = -1; // Mark the cell as visited
        int paths = solution(grid, m, n, i + 1, j, zeros - 1) +
                    solution(grid, m, n, i, j + 1, zeros - 1) +
                    solution(grid, m, n, i - 1, j, zeros - 1) +
                    solution(grid, m, n, i, j - 1, zeros - 1);
        grid[i][j] = 0; // Reset the cell after backtracking
        return paths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int start_i, start_j, zeros = 0;

        // Find the starting point and count the number of zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                } else if (grid[i][j] == 0 || grid[i][j] == 2) {
                    zeros++;
                }
            }
        }

        return solution(grid, m, n, start_i, start_j, zeros);
    }
};
