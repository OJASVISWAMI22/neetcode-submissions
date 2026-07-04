class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";

        auto &vect = mp[key];
        int n=vect.size();
        int s=0,e=n-1;
        string ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(vect[mid].first==timestamp){
                ans=vect[mid].second;
                break;
            }
            else if(vect[mid].first > timestamp){
                e=mid-1;
            }
            else{
                ans=vect[mid].second;
                s=mid+1;
            }
        }
        return ans;

    }
};
