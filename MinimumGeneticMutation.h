class Solution {
private:
    const int GENE_LENGTH = 8;
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> valid_mutations {bank.begin(), bank.end()};
        
        //check if the end string is a valid_mutation; return -1 otherwise
        if( !valid_mutations.count(end) )
            return -1;
        
        //BFS for the needed changes
        queue<string> q;
        q.push(start);
        int mutations = 0, q_remain;
        string cur, mutant;
        while(!q.empty()) {
            q_remain = q.size();
            while(q_remain--) {
                cur = q.front();
                q.pop();
                
                //end mutation reached; return necessary mutations
                if(cur == end) return mutations;
                
                //remove current mutation to avoid duplicate checking
                valid_mutations.erase(cur);
                
                //check possible mutations and add to queue
                for(int i=0; i<GENE_LENGTH; i++) {
                    mutant = cur;
                    mutant[i] = 'A';
                    if(valid_mutations.count(mutant)) q.push(mutant);
                    mutant[i] = 'C';
                    if(valid_mutations.count(mutant)) q.push(mutant);
                    mutant[i] = 'G';
                    if(valid_mutations.count(mutant)) q.push(mutant);
                    mutant[i] = 'T';
                    if(valid_mutations.count(mutant)) q.push(mutant);
                }
            }
            
            mutations++;
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/minimum-genetic-mutation/