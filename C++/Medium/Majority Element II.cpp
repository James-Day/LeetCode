#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> majorityElement(vector<int>& a)
	{
		int y, z, countY = 0, countZ = 0;
		for (const auto& x : a)
		{
			if (x == y) countY++;
			else if (x == z) countZ++;
			else if (!countY) y = x, countY = 1;
			else if (!countZ) z = x, countZ = 1;
			else countY--, countZ--;
		}

		countY = countZ = 0;
		for (const auto& x : a) //count the 2 candidates
			if (x == y) countY++;
			else if (x == z) countZ++;

		vector<int> r;
		if (countY > size(a) / 3) r.push_back(y); //add candidates if they appear > n/3 times
		if (countZ > size(a) / 3) r.push_back(z); //add candidates if they appear > n/3 times
		return r;
	}
};

// Worse solution: O(N) space complexity 

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int, int> count;
		for (int i = 0; i < nums.size(); i++) {
			count[nums[i]]++;
		}
		vector<int> ans;
		for (auto i = count.begin(); i != count.end(); i++) {
			if (i->second > nums.size() / 3) {
				ans.push_back(i->first);
			}
		}
		return ans;
	}
};