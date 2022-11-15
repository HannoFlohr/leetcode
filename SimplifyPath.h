class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string s;
        
        for(int i=0; i<path.size(); i++) {
            if(path[i] == '/') continue; 
            
            s = "";
            while(i < path.size() && path[i] != '/') 
                s += path[i++];
            
            if(s == ".") 
                continue;
            else if(s == "..") {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(s);
        }
        
        s = "";
        while(!st.empty()) {
            s = "/" + st.top() + s;
            st.pop();
        }
        
        return s.size() == 0 ? "/" : s;
    }
};
//https://leetcode.com/problems/simplify-path/