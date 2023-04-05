class BrowserHistory {
private:
    string history [5001];
    int current_site = 0, last_site = 0;
public:
    BrowserHistory(string homepage) {
        history[0] = homepage;
    }
    
    void visit(string url) {
        ++current_site;
        last_site = current_site;
        history[current_site] = url;
    }
    
    string back(int steps) { 
        current_site = max(0, current_site-steps); 
        return history[current_site];
    }
    
    string forward(int steps) {
        current_site = min(last_site, current_site+steps);
        return history[current_site];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
https://leetcode.com/problems/design-browser-history/