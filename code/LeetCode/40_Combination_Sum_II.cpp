class Solution {
    vector<vector<int>> result;
    vector<int> temp;
    void dfs(vector<int>& candidates, vector<int>& count, int begin, int target) {
        if (target == 0) {
            result.push_back(temp);
            return ;
        }
        if (target < 0 || begin >= (int) candidates.size()) return ;
        dfs(candidates, count, begin + 1, target);
        int num = candidates[begin];
        int max = 0;
        for (int i = 1; i <= count[begin] && i * num <= target; i++) {
            temp.push_back(num);
            max = i;
            dfs(candidates, count, begin + 1, target - i * num);
        }
        for (int i = 0; i < max; i++) {
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::reverse(candidates.begin(), candidates.end());
        vector<int> uni;
        vector<int> count;
        for (int i = 0; i < (int)candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i - 1]) {
                count[count.size() - 1]++;
            } else {
                uni.push_back(candidates[i]);
                count.push_back(1);
            }
        }
        dfs(uni, count, 0, target);
        return result;
    }
};
