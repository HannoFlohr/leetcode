class Solution {
public:
    string capitalizeTitle(string title) {
        int length = title.length();
        
        for(int i = 0; i < length; ++i) {
            int start_index = i;

            while(i < length && title[i] != ' ') {
                title[i] = tolower(title[i]);
                i++;
            }

            if(i - start_index > 2) {
                title[start_index] = toupper(title[start_index]);
            }
        }

        return title;
    }
};
//https://leetcode.com/problems/capitalize-the-title/