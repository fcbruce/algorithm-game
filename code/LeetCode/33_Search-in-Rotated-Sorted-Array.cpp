class Solution {
public:
    bool maybe_left(vector<int>& nums, int left, int right, int target) {
        return nums[left] > nums[right] && (target <= nums[right] || nums[left] <= target) 
            || nums[left] <= target && target <= nums[right];
    }
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int left = 0, right = length - 1;
        while (left <= right) {
            int mid = left + right >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (maybe_left(nums, left, mid, target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
