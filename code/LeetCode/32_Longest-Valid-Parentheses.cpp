class Solution {
public:
    bool match(std::string &s, std::stack<int> &st, char c) {
        return st.top() >= 0 && s[st.top()] == '(' && c == ')';
    }
    
    int longestValidParentheses(string s) {
        int length = s.length();
        std::stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < length; i++) {
            if (match(s, stack, s[i])) {
                stack.pop();
            } else {
                stack.push(i);
            }
        }
        int max = 0;
        int last = length;
        while (!stack.empty()) {
            max = std::max(max, last - stack.top() - 1);
            last = stack.top();
            stack.pop();
        }
        return max;
    }
};
