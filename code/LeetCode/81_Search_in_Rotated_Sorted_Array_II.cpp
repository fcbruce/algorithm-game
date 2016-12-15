class Solution {
public:
    bool maybe_left(vector<int>& nums, int left, int right, int target) {
        return nums[left] > nums[right] && (nums[left] <= target || target <= nums[right]) 
            || nums[left] <= target && target <= nums[right];
    }
    bool hard_judge(vector<int>& nums, int left, int right) {
        return nums[left] == nums[right];
    }
    bool search(vector<int>& nums, int target) {
        int length = nums.size();
        int left = 0, right = length - 1;
        while (left <= right) {
            int mid = left + right >> 1;
            if (target == nums[mid]) return true;
            if (hard_judge(nums, left, right)) {
                if (target == nums[left]) return true;
                left++;
                right--;
            } else if (maybe_left(nums, left, mid, target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
