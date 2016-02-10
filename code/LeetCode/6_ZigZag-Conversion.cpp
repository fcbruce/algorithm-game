class Solution {
public:
    string convert(string s, int numRows) {
        if (s == "") return "";
        string temp = "";
        int switch1 = numRows;
        int gap = -1;
        for (size_t i = 0; i < s.size(); i++) {
            if (switch1 == numRows) {
                temp += s[i];
            } else {
                fill(temp, switch1 - 1);
                temp += s[i];
                fill(temp, numRows - switch1);
            }
            if (temp.size() == numRows) {
                mat.push_back(temp);
                temp = "";
                switch1 += gap;
                if (switch1 <= 1) switch1 = numRows;
            }
        }
        if (temp != "") mat.push_back(temp);
        temp = "";
        for (size_t i = 0; i < mat[0].size(); i++) {
            for (size_t j = 0; j < mat.size(); j++) {
                if (i < mat[j].size() && mat[j][i] != ' ') temp += mat[j][i];
            }
        }
        return temp;
    }
    void fill(string& s, int k) {
        while (k--) s += ' ';
    }
private:
    vector<string> mat;
};
