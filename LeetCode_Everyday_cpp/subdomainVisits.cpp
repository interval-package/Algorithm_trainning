//
// Created by Zza on 2022/10/5.
//
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;


class Solution {
public:

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> _hashmap;
        istringstream iss;
        int times=0;
        string host;
        for(auto access: cpdomains){
            iss = istringstream(access);
            iss>>times>>host;
            _hashmap[host] += times;
            for(int iter=0; iter<host.length(); iter++){
                if(host[iter] == '.'){
                    _hashmap[host.substr(iter+1,-1)] += times;
                }
            }
            // cpdomains.emplace_back(host);
            host.clear();
        }
        cpdomains.clear();
        for(auto iter: _hashmap){
            cpdomains.emplace_back(to_string(iter.second)+" "+iter.first);
        }
        return cpdomains;
    }
};