#include <bits/stdc++.h>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    int dp[m][n];

    dp[m - 1][n - 1] = ((dungeon[m - 1][n - 1] <= 0) ? (-dungeon[m - 1][n - 1] + 1) : (1));

    for (int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = max(dp[i + 1][n - 1] + (-dungeon[i][n - 1]), 1);
    }

    for (int j = n - 2; j >= 0; j--) {
        dp[m - 1][j] = max(dp[m - 1][j + 1] + (-dungeon[m - 1][j]), 1);
    }


    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) + (-dungeon[i][j]), 1);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }


    return dp[0][0];
}

int getVal(vector<vector<int>> &mat, int i=0, int j=0) {
    int n = mat.size();
    int m = mat[0].size();
    // Base case : we have crossed the matrix, ie. out of bound
    /// if current row crosses then my row is below the princess or 
    /// if current column crosses then my column is ahead the column of princess
    /// and beacause we can go only down and right so we wont be able reach princess
    if(i == n || j == m)    return 1e9; 
    
    // Base Case : we have reached our destination ie. last cell
    /// we reached princess , cheers return this cost;\
    if(i == n-1 and j == m-1)   
        return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
    
    /// now we must try all possible paths , we ask our right and and down cell
    int IfWeGoRight = getVal(mat , i , j+1);
    int IfWeGoDown = getVal(mat , i+1 , j);
    
    /// min of either values and then cost of this cell
    int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
    
    /// point 2 as explained 
    return ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
}

int main(void) {

}