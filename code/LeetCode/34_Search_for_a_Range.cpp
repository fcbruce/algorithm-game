class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int lower = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (nums[lower] != target) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(lower);
        int upper = std::upper_bound(nums.begin() + lower, nums.end(), target) - nums.begin();
        result.push_back(upper - 1);
        return result;
    }
};
