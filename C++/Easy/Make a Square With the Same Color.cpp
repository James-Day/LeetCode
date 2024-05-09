class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int white = 0;
                int black = 0;
                grid[i][j] == 'W' ? white++ : black++;
                grid[i + 1][j] == 'W' ? white++ : black++;
                grid[i][j + 1] == 'W' ? white++ : black++;
                grid[i + 1][j + 1] == 'W' ? white++ : black++;
                if (black >= 3 || white >= 3) return true;
            }
        }
        return false;
    }
};
/* slower solution shows all possibilities.
* class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        vector<vector<char>> a = {{'W','B','W'},{'B','W','B'},{'W','B','W'}};
        vector<vector<char>> b = {{'B','W','B'},{'W','B','W'},{'B','W','B'}};
        vector<vector<char>> c = {{'W','W','W'},{'B','B','B'},{'W','W','W'}};
        vector<vector<char>> d = {{'B','B','B'},{'W','W','W'},{'B','B','B'}};
        vector<vector<char>> e = {{'W','B','W'},{'W','B','W'},{'W','B','W'}};
        vector<vector<char>> f = {{'B','W','B'},{'B','W','B'},{'B','W','B'}};
        vector<vector<char>> g = {{'W','B','B'},{'B','W','W'},{'W','B','B'}};
        vector<vector<char>> h = {{'B','W','W'},{'W','B','B'},{'B','W','W'}};
        vector<vector<char>> i = {{'W','B','W'},{'B','W','B'},{'B','W','B'}};
        vector<vector<char>> j = {{'B','W','B'},{'W','B','W'},{'W','B','W'}};
        vector<vector<char>> k = {{'W','B','W'},{'W','B','W'},{'B','W','B'}};
        vector<vector<char>> l = {{'B','W','B'},{'B','W','B'},{'W','B','W'}};
        vector<vector<char>> m = {{'W','W','B'},{'B','B','W'},{'W','W','B'}};
        vector<vector<char>> n = {{'B','B','W'},{'W','W','B'},{'B','B','W'}};
        
        vector<vector<vector<char>>> falses;
        falses.push_back(a);
        falses.push_back(b);
        falses.push_back(c);
        falses.push_back(d);
        falses.push_back(e);
        falses.push_back(f);
        falses.push_back(g);
        falses.push_back(h);
        falses.push_back(i);
        falses.push_back(j);
        falses.push_back(k);
        falses.push_back(l);
        falses.push_back(m);
        falses.push_back(n);

        for(int i = 0 ; i < falses.size(); i++){
            bool equal = true;
            for(int j = 0; j < 3; j++){
                for(int k = 0 ; k < 3; k++){
                    if(grid[j][k] != falses[i][j][k]) equal = false;
                }
            }
            if(equal) return false;
        }
        return true;
    }
};
*/