/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    var distance = 10000000, cloest = -1;
    nums.sort((a, b) => a - b);
    var l = nums.length;
    for (var i = 0; i < l - 2; i++) {
        var j = i + 1, k = l - 1;
        while (j < k) {
            var s = nums[i] + nums[j] + nums[k];
            if (Math.abs(target - s) < distance) {
                distance = Math.abs(target - s);
                cloest = s;
            }
            if (s < target) j++;
            else k--;
        }
    }
    return cloest;
};
