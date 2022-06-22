class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> validationMap;
  
        for(int i =0; i < board.size(); i++){
            //check row i
            for(int j =0; j < board.size(); j++){        
                validationMap[board[i][j]]++; //creates or updates value in validation map
            }
            for(int k=1; k <= board.size(); k++){
                char c = static_cast<char>(k) + 48;
                if(validationMap.find(c) != validationMap.end()){
                    if(validationMap[c] > 1){
                        return false;
                    }
                }
            }
            validationMap.clear();
            //check column i
            for(int l =0; l < board.size(); l++){
                validationMap[board[l][i]]++;
            }
            
            for(int p=1; p <= board.size(); p++){
                char c = static_cast<char>(p) + 48;
                if(validationMap.find(c) != validationMap.end()){
                    if(validationMap[c] > 1){
                        return false;
                    }
                }
            }
          validationMap.clear();            
        }
        
    //check sub boxes
        for(int down =0; down < board.size(); down = down + 3){
            for(int right =0; right < board.size(); right = right + 3){
                for(int i =0; i < 3; i++){
                    for(int j =0; j < 3; j++){
                        validationMap[board[i+right][j+down]]++;      
                    }
                }
                for(int p=1; p <= board.size(); p++){
                    char c = static_cast<char>(p) + 48;
                if(validationMap.find(c) != validationMap.end()){
                    if(validationMap[c] > 1){
                        return false;
                    }
                }
            }
          validationMap.clear();    
            }
        }
        return true;
    }
};