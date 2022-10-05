//
// Created by Zza on 2022/10/1.
//

#include <string>
#include <iostream>
using namespace std;

int tail_cast[] = {3, 4, 0, 0};

class Solution {
public:

    string reformatNumber(string number) {
        int count = 0, tail;
        for(auto iter = number.begin(); iter != number.end();iter++){
            if(count == 3){
                iter = number.insert(iter, '-');
                count = 0;

                continue;
            }

            if(*iter <= '9' && *iter>= '0'){

                count++;
            }
            else{

                iter = number.erase(iter);

                iter--;
            }
        }

        tail = tail_cast[count];
        if(tail){

            number.erase(number.end()-1-count);

            switch(count){
                case 0:{
                    break;
                }
                case 1:{
                    number.insert(number.end()-2,'-');
                    break;
                }
            }
        }


        return number;
    }
};

int main(){

    Solution obj;
    cout<<obj.reformatNumber("06903- --145704");

    return 0;
}