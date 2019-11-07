
//William Archbold
//LeetCode Practice 



/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/



#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{
	vector<int> candidate = { 2, 7, 11, 15 };

	int target = 9;

	vector<int> result = twoSum(candidate, target);

	return 0;
}


vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int>answer;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums.at(i) + nums.at(j) == target)
			{
				answer.push_back(i);
				answer.push_back(j);
				return answer;
			}
		}
	}
	return answer;
}