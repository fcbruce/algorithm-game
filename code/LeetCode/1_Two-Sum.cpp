class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i + 1});
        }
        sort(temp.begin(), temp.end());
        for (auto e : temp) {
            auto ret = lower_bound(temp.begin(), temp.end(), make_pair(target - e.first, e.second + 1));
            if (ret != temp.end() && e.first + ret->first == target) {
                return {e.second, ret->second};
            }
        }
        return vector<int>();
    }
};
