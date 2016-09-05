/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a, b) => a - b);
    var result = [];
    var l = nums.length;
    var last = null;
    for (var i = 0; i < l - 2; i++) {
        if (last === nums[i]) continue;
        var j = i + 1, k = l - 1;
        while (j < k) {
            var s = nums[i] + nums[j] + nums[k];
            if (s === 0) {
                result.push([nums[i], nums[j], nums[k]]);
                while (j < k && nums[i] + nums[j] + nums[k] === s) j++;
            }
            if (nums[i] + nums[j] + nums[k] < 0) j++;
            else k--;
        }
        last = nums[i];
    }
    return result;
};
