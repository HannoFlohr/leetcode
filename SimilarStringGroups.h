class DisjointSet {
		vector<int> ds;
		int size;

public:
		DisjointSet(int n) {
				ds.resize(n);
    		iota(ds.begin(), ds.end(), 0);
    		size = n;
		}

		int find(int i) {
				if (ds[i] != i)
						ds[i] = find(ds[i]);
				return ds[i];
		}

		bool Union(int set1, int set2) {
				int rank1 = find(set1), rank2 = find(set2);
				if(rank1 != rank2) {
						ds[rank1] = rank2;
						size--;
				}
				return true;
		}

		const int getSize() const {
				return size;
		}
};

class Solution {
private:
		bool isSimilarWord(const string& x, const string& y) {
				int differences = 0;
				for(size_t i = 0; i < x.size(); ++i)
						if((x[i] != y[i]) && (++differences > 2))
								return false;
				return true;
		}

public:
    int numSimilarGroups(vector<string>& strs) {
        const int words = strs.size();
				DisjointSet ds (words);

				for(size_t i = 0; i < words; ++i)
						for(size_t j = i+1; j < words; ++j)
								if(isSimilarWord(strs[i], strs[j]))
									ds.Union(i, j);
									
				return ds.getSize();
    }
};
//https://leetcode.com/problems/similar-string-groups/