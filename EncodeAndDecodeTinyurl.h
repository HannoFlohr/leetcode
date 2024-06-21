class Solution {
private:
    const string alphabet = "qwertzuiopasdfghjklyxcvbnmQWERTZUIOPASDFGHJKLYXCVBNM123456789";
    const int alphabet_size = alphabet.size();
    unordered_map<string,string> URLs;

    string generateShortUrl() {
        string shortUrl = "";
        int x = time(nullptr);
        while(x > 0) {
            shortUrl += alphabet[x%alphabet_size];
            x /= alphabet_size; 
        }
        return shortUrl;
    }

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = generateShortUrl();
        URLs[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return URLs[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

//https://leetcode.com/problems/encode-and-decode-tinyurl/