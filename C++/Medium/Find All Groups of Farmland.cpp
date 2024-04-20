class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[i].size(); j++) { //rather than removing land, just only chcek top left corners!
                if (land[i][j] == 1 && ((j == 0 || land[i][j - 1] == 0) && (i == 0 || land[i - 1][j] == 0))) {
                    vector<int> cords = { i,j };
                    int x = j;
                    int y = i;
                    while (x < land[y].size() && land[y][x] == 1) x++;
                    x--;
                    while (y < land.size() && land[y][x] == 1)  y++;
                    y--;
                    cords.insert(cords.end(), { y,x });
                    ans.push_back(cords);
                }
            }
        }
        return ans;
    }
};
/* Old solution that removed islands as to not double count.
* class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i = 0; i < land.size(); i++){
            for(int j = 0 ; j < land[i].size(); j++){
                if(land[i][j] == 1){
                    vector<int> cords = {i,j};
                    int x = j;
                    int y = i;
                    while(x < land[y].size() && land[y][x] == 1) x++; 
                    x--;
                    while(y < land.size() && land[y][x] == 1)  y++;
                    y--;
                    cords.insert(cords.end(), {y,x});
                    for(int a = i; a <= y; a++){
                        for(int b = j; b <= x; b++){
                            land[a][b] = 0;
                        }
                    }
                    ans.push_back(cords);
                }
            }
        }
        return ans;
    }
};
*/
/*
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i = 0; i < land.size(); i++){
            for(int j = 0 ; j < land[i].size(); j++){
                if(land[i][j] == 1){
                    vector<int> cords = {i,j};
                    vector<int> bR = bottomRight(land, i, j);
                    cords.insert(cords.end(), bR.begin(), bR.end());
                    ans.push_back(cords);
                }
            }
        }
        return ans;
    }
    vector<int> bottomRight(vector<vector<int>>& land, int i , int j){
        if( i >= land.size() || j >= land[i].size() || land[i][j] != 1) return {};
        land[i][j] = 0;
        vector<int> down = bottomRight(land, i + 1, j);
        vector<int> right = bottomRight(land, i, j + 1);
        vector<int> bottomRight = {i,j};
        if (down.empty() && right.empty()) return bottomRight;
        if (down.empty()) return right;
        return down;
    }
};
*/