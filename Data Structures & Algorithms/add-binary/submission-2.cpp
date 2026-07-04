class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        string s="";
        int i=0,carry=0;
        while(i<a.size() && i< b.size()){
            int numA=a[i]-'0';
            int numB=b[i]-'0';
            int ans=numA +  numB +carry;
            int bitToInsert=ans%2;
            carry= ans/2;
            s.push_back(bitToInsert+'0');
            i++;
        }
        while(i<a.size()){
            int numA=a[i]-'0';
            int ans=carry+numA;
            int toInsert=ans%2;
            carry=ans/2;
            s.push_back(toInsert+'0');
            i++;
        }
        while(i<b.size()){
            int numB=b[i]-'0';
            int ans=numB + carry;
            int toInsert=ans%2;
            carry=ans/2;
            s.push_back(toInsert+'0');
            i++;
        }
        if(carry){
            s.push_back('1');
        }
        reverse(s.begin(),s.end());
    return s;
    }
};