class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int result = 0;

        for(int i=0;i<operations.size();i++){
            if(operations[i]=="D"){
                s.push(2*s.top());
            }
            else if(operations[i]=="C"){
                s.pop();
            }
            else if(operations[i]=="+"){
                int temp = s.top();
                s.pop();
                int sum = s.top()+temp;
                s.push(temp);
                s.push(sum);
            }
            else{
                s.push(stoi(operations[i]));
            }
        }

        while(s.size()>0){
            result += s.top();
            s.pop();
        }

        return result;
    }
};