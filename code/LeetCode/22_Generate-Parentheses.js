/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var result = [];
    var dfs = function(str, remain, active) {
        if (remain === 0 && active === 0) {
            return result.push(str);
        }
        if (remain > 0) {
            dfs(str + '(', remain - 1, active + 1);
        }
        if (active > 0) {
            dfs(str + ')', remain, active - 1);
        }
    }
    dfs('', n, 0);
    return result;
};
