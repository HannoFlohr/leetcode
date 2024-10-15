class Solution {
public:
    string convertDateToBinary(string date) {
        const char separator = '-';
        string converted = "";
        for(int start = 0, end = 0; start < date.size(); ) {
            while(end <= date.size() && date[end] != separator) {
                ++end;
            } 

            int number = stoi(date.substr(start, end-start)); 
            string binary = bitset<32>(number).to_string(); 
            binary.erase(0, binary.find_first_not_of('0')); 
            converted += binary + separator;

            start = end+1;
            end = start;
        }
    
        converted.pop_back();
        return converted;
    }
}; //runtime 50.63%, memory 81.33%
//https://leetcode.com/problems/convert-date-to-binary/

/*
class Solution {
private:
    string convert(string s) {
        string converted = "";
        int number = 0;
        for(char c : s) 
            number = number*10 + c-'0';

        while(number > 0) {
            converted = (number%2 == 0 ? "0" : "1") + converted;
            number /= 2;
        }
        return converted;
    }
public:
    string convertDateToBinary(string date) {
        return convert(date.substr(0,4)) + "-" + convert(date.substr(5,2)) + "-" + convert(date.substr(8,2));
    }
}; //runtime 100%, memory 39.13%
*/ 