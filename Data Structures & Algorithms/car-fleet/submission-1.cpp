class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cartime;
        for(int i=0;i<position.size();i++){
            double time=(double)(target-position[i])/speed[i];
            cartime.push_back({position[i],time});
        }
        sort(cartime.rbegin(),cartime.rend());
        double time=0;
        int fleet=0;
        for(auto& [p,t]:cartime){
            if(t>time){
                time=t;
                fleet++;
            }
        }
        return fleet;
    }
};
