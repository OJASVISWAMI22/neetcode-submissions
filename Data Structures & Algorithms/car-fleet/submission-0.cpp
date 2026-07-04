class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // vector<pair<int,int>>cars;
        vector<pair<int,double>>cartime;
        // for(int i=0;i<position.size();i++){
        //     cars.push_back({position[i],speed[i]});
        // }
        // sort(cars.rbegin(),cars.rend());
        for(int i=0;i<position.size();i++){
            double time=(double)(target-position[i])/speed[i];
            cartime.push_back({position[i],time});
        }
        sort(cartime.rbegin(),cartime.rend());
        double time=0;
        int fleet=0;
        for(auto& [p,t]:cartime){
            if(time==0){
                fleet++;
                time=t;
            }
            else if(t>time){
                time=t;
                fleet++;
            }
        }
        return fleet;
    }
};
