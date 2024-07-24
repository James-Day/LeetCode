//fastest runtime solution.
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto translate_integer = [&](int num) -> int {
            string digits = to_string(num);
            for (char& digit : digits) {
                digit = '0' + mapping[digit - '0'];
            }
            return stoi(digits);
            };

        vector<pair<int, int>> map;
        for (int num : nums) {
            if (.find(num) == number_mapping.end()) {
                number_mapping[num] = translate_integer(num);
            }
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return number_mapping[a] < number_mapping[b];
            });

        return nums;
    }
};

//map solution
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            string word = to_string(nums[i]);
            for (int j = 0; j < word.size(); j++) {
                word[j] = '0' + (mapping[word[j] - '0']);
            }
            map[nums[i]] = (stoi(word));
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return map[a] < map[b];
            });
        return nums;
    }
};

//Likely better map solution (for some reason I am getting slower run times, but I would assume storing less numbers would be better with massive input sizes)
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto translate_integer = [&](int num) -> int {
            string digits = to_string(num);
            for (char& digit : digits) {
                digit = '0' + mapping[digit - '0'];
            }
            return stoi(digits);
            };

        unordered_map<int, int> number_mapping;
        for (int num : nums) {
            if (number_mapping.find(num) == number_mapping.end()) { //slower cause we are looking up twice potentially, but should decrease the memory usage slightly
                number_mapping[num] = translate_integer(num);
            }
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return number_mapping[a] < number_mapping[b];
            });

        return nums;
    }
};

// Done inline to use less memory. (not storing the string copies anywhere, just calculating it every single time we compare.)
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            string word = to_string(a);
            string word2 = to_string(b);
            for (int j = 0; j < word.size(); j++) {
                word[j] = '0' + (mapping[word[j] - '0']);
            }
            for (int j = 0; j < word2.size(); j++) {
                word2[j] = '0' + (mapping[word2[j] - '0']);
            }
            int mapa = stoi(word);
            int mapb = stoi(word2);

            if (mapa == mapb) {
                return false;
            }
            return mapa < mapb;
            });
        return nums;
    }
};
