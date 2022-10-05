//
// Created by Zza on 2022/10/2.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const char* data[] ={
        "XXXXXLXXXLXXXX",
        "XXLXXXXXXXXLXX"
};


class Solution {
public:

    bool pos_fit_L(string &start, string &end){
        int pos_s=0, pos_e=0;

        while (pos_s < start.length()){
            pos_s = start.find('L',pos_s);
            pos_e = end.find('L',pos_e);
            if(pos_s == string::npos || pos_e == string::npos)break;
            if(pos_s > pos_e)return false;
            pos_s++; pos_e++;
        }

        return true;
    }

    bool pos_fit_R(string &start, string &end){
        int pos_s=0, pos_e=0;

        while (pos_s < start.length()){
            pos_s = start.find('R',pos_s);
            pos_e = end.find('R',pos_e);
            if(pos_s == string::npos || pos_e == string::npos)break;
            if(pos_s < pos_e)return false;
            pos_s++; pos_e++;
        }

        return true;
    }


    bool pos_fit(string &start, string &end){
        start.erase(remove( start.begin(),  start.end(),  'X' ),  start.end() );
        end.erase(remove( end.begin(),  end.end(),  'X' ),  end.end() );
        return !start.compare(end);
    }

    bool canTransform(string start, string end) {
        if(start.size()!=end.size())return false;

        if(pos_fit_L(start,end) && pos_fit_R(start, end)){
            return pos_fit(start,end);
        } else{
            return false;
        }
    }
};


int main() {
    Solution obj;


    string s1 = data[0],s2=data[1];

    cout<<obj.canTransform(s1, s2);
    return 0;
}
