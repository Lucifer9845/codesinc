
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to find maximum sum submatrix
void maxSubmatrixSum(
    vector<vector<int> > matrix)
{
    // Stores the number of rows
    // and columns in the matrix
    int r = matrix.size();
    int c = matrix[0].size();
 
    // Stores maximum submatrix sum
    int maxSubmatrix = 0;
 
    // Take each row as starting row
    for (int i = 0; i < r; i++) {
 
        // Take each column as the
        // starting column
        for (int j = 0; j < c; j++) {
 
            // Take each row as the
            // ending row
            for (int k = i; k < r; k++) {
 
                // Take each column as
                // the ending column
                for (int l = j; l < c; l++) {
 
                    // Stores the sum of submatrix
                    // having topleft index(i, j)
                    // and bottom right index (k, l)
                    int sumSubmatrix = 0;
 
                    // Iterate the submatrix
                    // row-wise and calculate its sum
                    for (int m = i; m <= k; m++) {
                        for (int n = j; n <= l; n++) {
                            sumSubmatrix += matrix[m][n];
                        }
                    }
 
                    // Update the maximum sum
                    maxSubmatrix
                        = max(maxSubmatrix,
                              sumSubmatrix);
                }
            }
        }
    }
 
    // Print the answer
    cout << maxSubmatrix;
}
 
// Driver Code
int main()
{
    int a, b;
    cin>>a>>b;
    vector<vector<int> > matrix = { { 0, -2, -7, 0 },
                                    { 9, 2, -6, 2 },
                                    { -4, 1, -4, 1 },
                                    { -1, 8, 0, -2 } };
 
    maxSubmatrixSum(matrix);
    cout<<a<<b;
    return 0;
}