class Solution {
public:
    int countDigitOne(int n) {
        int counter = 0;
        for(long i=1; i<=n; i*=10) {
            long tmp = i*10;
            counter += ((n/tmp) * i) + min(max(n%tmp - i + 1, 0L), i);
        }
        return counter;
    }
};
//https://leetcode.com/problems/number-of-digit-one/

/*
1's at ones position:
1 11 21 31 41 51 61 71 81 91 

1's at tens position:
10 110 210 310 ...
11 111 211 311 ...
..
19 119 219 319 ...

1's at hundreds position:
100 1100 2100 ..
101 1101 2101 ..
...
199	1199 2199 ..

we can see clusters (10,100,1000,..) of number 1 for each step (ones,tens,hundreds..)
10 in ones
100 in tens
1000 in hundreds
...

so answer will be
sum of (n / cluster_size) * step

most likely there is one last cluster that is not complete, e.g. for n=1234 we sum up
for ones, tens and hundreds - so we have to take care of the final 234 < thausands
*/