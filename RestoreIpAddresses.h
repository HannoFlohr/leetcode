class Solution {
private:
    vector<string> valid_addresses;
    int length;
    
    void dfs(string s, string cur_ip, int start, int digit) {
        if(start == length && digit == 4) { //end of s reached and valid ip
            cur_ip.erase(cur_ip.end()-1);
            valid_addresses.push_back(cur_ip);
            return;
        }
        
        //filter out remaining lengths of wrong size
        if(length - start > (4 - digit) * 3) return;
        if(length - start < 4 - digit) return;
        
        int n = 0;
        for(int i=start; i<start+3; i++) { //find valid n <= 255 and dfs try to make valid ip adress
            n = n * 10 + (s[i]-'0');
            if(n <= 255) {
                cur_ip += s[i];
                dfs(s, cur_ip+'.', i+1, digit+1);
            }
            if(n == 0) break;
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        string cur_ip;
        length = s.size();
        dfs(s, cur_ip, 0, 0);
        return valid_addresses;
    }
};
//https://leetcode.com/problems/restore-ip-addresses/