#include<iostream>
using namespace std;
const int n = 9;
void display(int board[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isValid(int board[n][n], int row, int col, int num){
    //check in row
    for(int i=0;i<n;i++){
        if(board[row][i] == num){
            return false;
        }
    }
    //check in col
    for(int i=0;i<n;i++){
        if(board[i][col] == num){
            return false;
        }
    }
    //check in grid
    int startRow = row - row%3;
    int startCol = col - col%3;
    for(int i=startRow;i<startRow+3;i++){
        for(int j=startCol;j<startCol+3;j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int board[n][n]){
    int row,col;
    bool isEmpty = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 0){
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if(isEmpty){
            break;
        }
    }
    if(!isEmpty){
        return true;
    }
    for(int num=1;num<=9;num++){
        if(isValid(board,row,col,num)){
            board[row][col] = num;
            if(solveSudoku(board)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}
int main(){
    int board[n][n] = {
                        {0,0,0,2,6,0,7,0,1},
                        {6,8,0,0,7,0,0,9,0},
                        {1,9,0,0,0,4,5,0,0},
                        {8,2,0,1,0,0,0,4,0},
                        {0,0,4,6,0,2,9,0,0},
                        {0,5,0,0,0,3,0,2,8},
                        {0,0,9,3,0,0,0,7,4},
                        {0,4,0,0,5,0,0,3,6},
                        {7,0,3,0,1,8,0,0,0},
                     };
    if(solveSudoku(board)){
        display(board);
    }else{
        cout << "Solution does not exist" << endl;
    }
    return 0;
}
