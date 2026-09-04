class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open; // open bracket indices
        stack<int> star; // wild card indices
        for(int i = 0; i< s.size(); i++) {
            char ch = s[i];
            if(ch == '(') open.push(i);
            else if(ch == '*') star.push(i);
            else {
                if(!open.empty()) open.pop(); // match open brackets first
                else if(!star.empty()) star.pop(); // then match wild card indices
                else return false;
            }
        }
        while(!open.empty() && !star.empty()) {
        // if open bracket comes after a wild card index, then its pair is not made
            if(open.top() > star.top()) return false;
            open.pop();
            star.pop();
        }
        return open.empty();
    }
};
