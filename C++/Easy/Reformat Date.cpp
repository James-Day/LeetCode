class Solution { //small vector is better than all the overhead with creating a hashmap.
public:
    string reformatDate(string date) {
        string day;
        string month;
        string year;
        vector<string> map = {
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec",
        };

        int i = 0;
        for (; i < date.length(); i++) {
            if (date[i] == ' ') break;
            day += date[i];
        }
        i++;
        for (; i < date.length(); i++) {
            if (date[i] == ' ') break;
            month += date[i];
        }
        i++;
        for (; i < date.length(); i++) {
            if (date[i] == ' ') break;
            year += date[i];
        }

        day = day.substr(0, day.size() - 2);
        int monthDig = 0;
        if (day.length() == 1) day = "0" + day;
        for (int i = 0; i < map.size(); i++) {
            if (map[i] == month) monthDig = i;
        }
        month = to_string(monthDig + 1);
        if (to_string(monthDig + 1).length() <= 1) {
            month = "0" + month;
        }
        return year + "-" + month + "-" + day;
    }
};

/*
class Solution {
public:
    string reformatDate(string date) {
        string day;
        string month;
        string year;
        unordered_map<string, string> map = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"},
        };

        int i = 0;
        for(; i < date.length(); i++){
            if(date[i] == ' ') break;
            day += date[i];
        }
        i++;
        for(; i < date.length(); i++){
            if(date[i] == ' ') break;
            month += date[i];
        }
        i++;
        for(; i < date.length(); i++){
            if(date[i] == ' ') break;
            year += date[i];
        }

        day = day.substr(0, day.size() - 2);
        if (day.length() == 1) day = "0" + day;

        return year + "-" + map[month] + "-" + day;
    }
};

*/