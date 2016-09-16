/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    var length = nums.length;
    nums.sort((a, b) => a - b);
    var result = [];
    for (var i = 0; i < length; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue;
        for (var j = i + 1; j < length; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue;
            var k = j + 1, l = length - 1, sum2 = nums[i] + nums[j];
            while (k < l) {
                if (sum2 + nums[k] + nums[l] === target) {
                    result.push([nums[i], nums[j], nums[k], nums[l]]);
                    k++;
                    while (k < l && nums[k] === nums[k - 1]) k++;
                } else if (sum2 + nums[k] + nums[l] < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    return result;
};

