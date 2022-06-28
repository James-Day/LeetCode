class Solution {
    public:
    int myAtoi(string s) {
        int counter =0;
        int negative = 1;
        string result = "";
        long val =0;
        while(counter < s.size() && s.at(counter) == ' '){
            counter++;
        } 
        if(counter < s.size() && s.at(counter) == '-'){ // check for negative
            negative =  -1;
            counter++;
        }
        else if(counter < s.size() && s.at(counter) == '+'){
            counter++;
        }
        while(counter < s.size() && (s.at(counter) <= '9' && s.at(counter) >= '0')){
            result += s.at(counter);
            counter++;
        }   
        int zeroCounter =0;
        while(zeroCounter < result.size() && result.at(zeroCounter) == '0'){
            zeroCounter++;
        }
    
        for( ;zeroCounter < result.size(); zeroCounter++){
           val *= 10;
           val += result.at(zeroCounter) - '0';
            if(val * negative < INT_MIN){
               return INT_MIN;
            }
            if(val * negative > INT_MAX){
               return INT_MAX;
            }
        }
        return val * negative;
    }
        
};