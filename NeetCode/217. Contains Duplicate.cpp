#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> sets;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sets.find(nums[i]) != sets.end())
            {
                return true;
            }
            sets.insert(nums[i]);
        }
        return false;
    }
};