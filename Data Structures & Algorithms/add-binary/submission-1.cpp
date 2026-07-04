class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        string s="";
        int i=0,carry=0;

        while(i<a.size() && i<b.size()){
            int numa=a[i]-'0';
            int numb=b[i]-'0';
            int ansBit=numa^numb^carry;
            carry=(numa & numb) | (carry & (numa^numb));
            s.push_back(ansBit+'0');
            i++;
        }
        while(i<a.size()){
            int numa=a[i]-'0';
            int ansBit=numa^carry;
            carry=carry&numa;
            s.push_back(ansBit+'0');
            i++;
        }

        while(i<b.size()){
            int numb=b[i]-'0';
            int ansBit=numb^carry;
            carry=carry&numb;
            s.push_back(ansBit+'0');
            i++;
        }
        if(carry){
            s.push_back('1');
        }
    reverse(s.begin(),s.end());
    return s;
    }
};