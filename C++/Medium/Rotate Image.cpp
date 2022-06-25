class Solution { //my solution
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size(); // nxn array, n is the length and width of the 2D array
        int currSize = n;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < currSize - 1; j++) {
                int temp = matrix[i][j + i];
                matrix[i][j + i] = matrix[n - j - i - 1][i];
                matrix[n - j - i - 1][i] = matrix[n - i - 1][n - i - j - 1];
                matrix[n - i - 1][n - i - j - 1] = matrix[i + j][n - i - 1];
                matrix[i + j][n - i - 1] = temp;
            }
            currSize -= 2;
        }
    }
};

/* //"proper" solution (very similar), starts at bottom left corner instead of top left.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix[0].size(); // length of one row
        for(int i =0; i < length/2 + length%2;i++){
            for(int j =0; j< length/2; j++){
                int temp = matrix[length-j-1][i];
                matrix[length-j-1][i] = matrix[length-i-1][length-j-1];
                matrix[length-i-1][length-j-1] = matrix[j][length-i-1];
                matrix[j][length-i-1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};

*/