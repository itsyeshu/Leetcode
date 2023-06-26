class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Citations : |1|3|1|

        vector<int> papers(1001, 0);
        // Papers    : |0|0|0|0|0|...|0|

        for(int citation : citations){
            papers[citation]++;
        }
        // Papers    : |0|2|0|1|0|...|0|

        int h_index = papers.size() - 1;
        for(int i=papers.size() - 2; i>=0; i--){
            papers[i] += papers[i+1];
        }
        while(papers[h_index] < h_index){
            h_index--;
        }
        h_index = max(h_index, 0);
        // Papers    : |3|3|1|1|0|...|0|
        //                ^
        //            h-index (1)

        return h_index;
    }
};