class Solution {
public:
    void dfs(vector<int>& can, int begin, int target, vector<vector<int>>& result, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return ;
        }
        if (target < 0) return ;
        if (begin >= (int)can.size()) return ;
        int number = can[begin];
        dfs(can, begin + 1, target, result, current);
        for (int i = 1; i * number <= target; i++) {
            current.push_back(number);
            dfs(can, begin + 1, target - number * i, result, current);
        }
        for (int i = 1; i * number <= target; i++) {
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        dfs(candidates, 0, target, result, temp);
        return result;
    }
};
