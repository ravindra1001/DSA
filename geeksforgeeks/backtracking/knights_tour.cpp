#include <bits/stdc++.h>
using namespace std;
int N = 8;

void print_grid(const vector<vector<int> >&grid){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<"    ";
        }
        cout<<endl;
    }
}

bool is_valid_move(const vector<vector<int> > &grid, int next_x, int next_y){
    if(next_x >= 0 && next_x < N &&
        next_y>=0 && next_y <N &&
        grid[next_x][next_y] == -1
    ) return true;

    return false;
}

bool utility_knights_tour(vector<vector<int> > &grid, int current_x, int current_y, int count, const vector<pair<int, int> >&moves){
    if(count==N*N){
        return true;
    }

    for(int i=0; i<moves.size();i++){
        int next_x = current_x + moves[i].first;
        int next_y = current_y + moves[i].second;

        if(is_valid_move(grid, next_x, next_y)){
            grid[next_x][next_y] = count;
            if(utility_knights_tour(grid, next_x, next_y, count+1, moves)==true){
                return true;
            }
            else{
                grid[next_x][next_y] = -1;
            }
        }
    }
    return false;
}

void knights_tour(){
    vector<vector<int> >grid(N, vector<int>(N, -1));
    vector<pair<int, int> >moves = {make_pair(2,1), 
                                    make_pair(1,2),
                                    make_pair(-1,2),
                                    make_pair(-2,1),
                                    make_pair(-2,-1),
                                    make_pair(-1,-2),
                                    make_pair(1,-2),
                                    make_pair(2,-1)};

    grid[0][0] = 0;    
    int current_x = 0;
    int current_y = 0;
    int count = 1;

    if(utility_knights_tour(grid, current_x, current_y, count, moves)==true){
        print_grid(grid);
    }
    else{
        cout<<"solution does not exist"<<endl;
    }
}

int main(){
    knights_tour();
    return 0;
}
