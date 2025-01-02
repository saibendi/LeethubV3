class Solution {
public:
    bool isValid(string s) {
        stack<char> k; 
        unordered_map<char,char> m = {{'}','{'}, {']','['}, {')', '('}};

        for (auto c : s) {
            if (m.count(c)) {
                if (!k.empty() && k.top() == m[c]) {
                    k.pop();
                }
                else {
                    return false;
                }
            }
            else {
                k.push(c);
            }
        }
        return k.empty(); 
    }
};