/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    var len = digits.length;
    var result = [];
    var dfs = function (s, i) {
        if (i === len) {
            if (s !== '') result.push(s);
            return ;
        }
        var d = digits.charCodeAt(i) - '0'.charCodeAt(0);
        if (d < 2) dfs(s, i + 1);
        else {
            var l = (d - 2) * 3;
            if (d > 7) l += 1;
            var r = l + 3;
            if (d === 7 || d === 9) r += 1;
            for (let j = l; j < r; j++) {
                var c = String.fromCharCode('a'.charCodeAt(0) + j);
                dfs(s + c, i + 1);
            }
        }
    }
    dfs('', 0);
    return result;
};
