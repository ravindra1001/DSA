#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<vector<int> >grid, int num, int x, int y){
    grid[x][y] = num;
    for(int i=0;i<9;i++){
        int row[10] = {0};
        int column[10] = {0};
        for(int j=0;j<9;j++){
            if(grid[i][j] != 0 && row[grid[i][j]]==1) return false;
            if(grid[j][i] != 0 && column[grid[j][i]]==1) return false;
            row[grid[i][j]] = 1;
            column[grid[j][i]] = 1;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int temp[10] = {0};
            for(int k = 3*i;k<3*(i+1);k++){
                for(int l = 3*j;l<3*(j+1);l++){
                    if(grid[k][l] != 0 && temp[grid[k][l]]==1) return false;
                    temp[grid[k][l]] = 1;
                }
            }
        }
    }
    return true;
}

pair<int,int> next_position(const vector<vector<int> >&grid){
    int n = 9;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

bool utility_solve_sudoku(vector<vector<int> >&grid){
    pair<int,int>p = next_position(grid);
    if(p.first==-1) return true;

    for(int i=1;i<=9;i++){
        if(is_valid(grid, i, p.first, p.second)){
            grid[p.first][p.second] = i;
            if(utility_solve_sudoku(grid)==true)return true;
            grid[p.first][p.second] = 0;
        }
    }
    return false;
}


void solve_sudoku(){
    vector<vector<int> >grid{{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(utility_solve_sudoku(grid)){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<"    ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"solution does not exist"<<endl;
    }

}
int main(){
    solve_sudoku();
    return 0;
}