class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string s;
        int n = words.size();
        
        for(int i=0, last, width; i<n; i += last) {
            //find the last index that can be used for the current line
            for(last = width = 0; i + last < n && width + words[i+last].size() <= maxWidth - last; last++) 
                width += words[i+last].size();
            
            //for each line words[i] to words[i+last-1] can be used
            s = words[i];
            for(int j=0; j<last-1; j++) {
                if(i + last >= n) s += " ";
                else s += string((maxWidth - width) / (last - 1) + (j < (maxWidth - width) % (last - 1)), ' '); 
                s += words[i+j+1];
            }
            
            s += string(maxWidth - s.size(), ' ');
            result.push_back(s);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/text-justification/

/*
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> lines;
        vector<string> line;
        int line_length = 0;

        //match words to lines 
        for(const string& word : words) {
            if(line_length + line.size() + word.length() <= maxWidth) {
                line.push_back(word);
                line_length += word.length();
            }
            else {
                lines.push_back(line);
                line.clear();
                line.push_back(word);
                line_length = word.length();
            }
        }
        lines.push_back(line);

        //fill lines (except last one) with appropriate spaces
        vector<string> justified_lines;
        int words_in_line, spaces, gaps, spaces_per_gap, extra_spaces, add_spaces;
        for(int i = 0; i < lines.size()-1; ++i) {
            line = lines[i];
            words_in_line = line.size();
            spaces = maxWidth;
            for(const string& word : line)
                spaces -= word.length();

            gaps = max(words_in_line-1, 1);
            spaces_per_gap = spaces / gaps;
            extra_spaces = spaces % gaps;

            string justified_line = "";
            for(const string& word : line) {
                justified_line += word;

                if(gaps > 0) {
                    add_spaces = spaces_per_gap + (extra_spaces > 0 ? 1 : 0);
                    justified_line += string(add_spaces, ' ');
                    --extra_spaces;
                    --gaps;
                }
            }

            justified_lines.push_back(justified_line);
        }

        //fill last line
        string last = "";
        for(const string& word : lines[lines.size()-1])
            last += word + " ";
        last.pop_back();
        last += string(maxWidth - last.length(), ' ');
        justified_lines.push_back(last);

        return justified_lines;
    }
};
*/