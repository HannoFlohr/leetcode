class ATM {
private:
    const vector<int> notes = {20, 50, 100, 200, 500};
    vector<int> available;
public:
    ATM() {
        available = vector<int>(5,0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++) {
            available[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> hand_out (5,0);

        for(int i = 4; i >= 0; i--) {
            if(amount < notes[i])
                continue;

            int x = amount / notes[i];
            x = min(x, available[i]);
            hand_out[i] += x;
            amount -= x * notes[i];
        }

        if(amount > 0) {
            return {-1};
        }

        for(int i = 0; i < 5; i++) {
            available[i] -= hand_out[i];
        }
        return hand_out;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
 
 //https://leetcode.com/problems/design-an-atm-machine/