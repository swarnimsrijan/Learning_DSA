#include<bits/stdc++.h>
using namespace std;

int M, N;

void print_paths(vector<int>& path){
    for(int i: path){
        cout << i << ", "; 
    }
    cout << endl;
}

void solution(int i, int j, vector<vector<int>>& grid, vector<int>& path){
    if(i == M -1 && j == N - 1){
        path.push_back(grid[i][j]);
        print_paths(path);
        path.pop_back();
        return;
    }

    if(i < 0 && i >= M && j < 0 && j >= N) return;

    path.push_back(grid[i][j]);

    if(j + 1 < N){
        solution(i, j + 1, grid, path);
    }
    if(i + 1 < M){
        solution(i + 1, j, grid, path);
    }

    path.pop_back();
}


int main()
{
    vector<vector<int> > grid
        = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
 
    vector<int> path;
    M = grid.size();
    N = grid[0].size();
 
    // Function call
    solution(0, 0, grid, path);
 
    return 0;
}

//Tc - O(2^mn)
//Sc - O(M + N)