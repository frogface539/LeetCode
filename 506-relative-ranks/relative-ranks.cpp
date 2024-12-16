class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<int> sortedScore;
        sortedScore=score; 
        sort(sortedScore.begin(),sortedScore.end(),greater<int>());
        vector<string>ans;
        for(int i=0;i<sortedScore.size();i++)
        {
            auto j =find(sortedScore.begin(),sortedScore.end(),score[i]);
            int z = abs(sortedScore.begin()-j) +1;
            if(z==1)
            {
                ans.push_back("Gold Medal");
            }

            else if(z==2)
            {
                ans.push_back("Silver Medal");
            }

            else if(z==3)
            {
                ans.push_back("Bronze Medal");
            }
            else
            {
                ans.push_back(to_string(z));
            }
        }
        return ans;
    }
};