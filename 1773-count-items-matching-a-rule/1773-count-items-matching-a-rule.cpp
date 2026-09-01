class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for(int i=0;i<items.size();i++){
            if("type"==ruleKey && items[i][0]==ruleValue || "color"==ruleKey && items[i][1]==ruleValue || "name"==ruleKey && items[i][2]==ruleValue){
                count++;
            }
        }
        return count;
    }
};