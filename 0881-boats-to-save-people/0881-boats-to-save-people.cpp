class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int r = people.size()-1;
        int l = 0;
        int count = 0;

        while(l<=r){
            if(people[l]+people[r]<=limit){
                count++;
                r--;
                l++;
            }
            
            else if(people[r]==limit){
                count++;
                r--;
            }
            
            else{
                r--;
                count++;
            }
            
            
        }
        return count;
    }
};