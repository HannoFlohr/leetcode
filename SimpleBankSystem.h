class Bank {
private:
    vector<long long> accounts = vector<long long>(1,0);
    
    bool validAccountNumber(int accountNumber) {
        return 1 <= accountNumber && accountNumber <= accounts.size();
    }

public:
    Bank(vector<long long>& balance) {
        accounts.insert(accounts.end(), balance.begin(), balance.end());
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!validAccountNumber(account1) || !validAccountNumber(account2))
            return false;

        if(accounts[account1] < money)
            return false;

        accounts[account1] -= money;
        accounts[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!validAccountNumber(account))
            return false;

        accounts[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!validAccountNumber(account))
            return false;

        if(accounts[account] < money)
            return false;

        accounts[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
 
 //https://leetcode.com/problems/simple-bank-system/