class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans=0;
        stack<int>s;
        for(auto it:operations){
            if(it=="C"){
                s.pop();
            }
            else if(it=="+"){
                int i=s.top();
                s.pop();
                int j=s.top();
                s.push(i);
                i+=j;
                s.push(i);
            }
            else if( it=="D"){
                int i=s.top();
                s.pop();
                s.push(i);
                i*=2;
                s.push(i);
            }
            else{
                s.push(stoi(it));
            }
        }

        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }

        return ans;
    }
};