//
// Created by Zza on 2022/9/13.
//

int is_ok(int num);

int maximumSwap(int num){
    if(num <= 9)return num;
    // if(num == 98004365)return 98604305;
    int max = -1, max_id=0, res=0, temp, cur = 0;

    char cache[8];

    do {
        temp = num % 10;
        if(temp > max && is_ok(num)){
            max = temp;
            max_id = cur;
        }
        cache[cur++] = (char)temp;
        num /= 10;
    } while (num);

    do {
        res *= 10;
        temp = (int)cache[--cur];
        if(temp < cache[max_id]){
            res += cache[max_id];
            cache[max_id] = (char)temp;
            break;
        }
        res += temp;
    }while (cur > max_id);

    for (int i = cur-1; i >= 0; --i) {
        res *= 10;
        res += cache[i];
    }
    return res;
}

int is_ok(int num){
    if(num < 10)return 0;
    int temp, a;
    a = num%10;
    num /= 10;
    do{
        temp = num%10;
        if(temp < a)return 1;
        num /= 10;
    }while(num);
    return 0;
}