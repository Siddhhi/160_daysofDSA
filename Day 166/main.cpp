/*
    Title: Convert Integer to English Words

    Problem Statement:
        - Given a non-negative integer `n`, convert it into its equivalent English words.
        - The output should be properly spaced and formatted.
        - Handle numbers in the range of billions, millions, thousands, hundreds, tens, and units.

    Author: Siddhi
*/


#include<bits/stdc++.h>
using namespace std;

string convertToWords(int n) {
    // code here
    if(n==0){
        return "Zero";
    }
    vector<string> unit = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
        "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
    };
    
    vector<string> tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    vector<string> multiplier = {"","Thousand","Million","Billion"};
    
    string res = "";
    int group=0;
    while(n>0){
        if(n%1000!=0){
            int val = n%1000;
            string temp = "";
            
            
            if(val>=100){
                temp=unit[val/100]+" Hundred ";
                val%=100;
            }
            
            if(val>=20){
                temp+=tens[val/10]+ " ";
                val%=10;
            }
            
            if(val>0){
                temp+=unit[val]+" ";
            }
            
            temp+=multiplier[group]+" ";
            
            res=temp+res;
        }
        
        n/=1000;
        group++;
    }
    return res.substr(0,res.find_last_not_of(" ")+1);
}


int main(){
    
    int n = 25006326;
    string res = convertToWords(n);
    
    cout<<"Number name to the integer "<<n<<" is "<<res<<"\n";
    
    return 0;
}
