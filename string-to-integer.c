/**
 * Author: Shaoqian Zhou
 * Date: Mar. 27th 2021
 */

int myAtoi(char * s){
    // get the sign
    int length = strlen(s);
    int result = 0;
    int pos = 0;
    int read = 0;
    int digits[10] = {0};
    int positive = -1;
    int nonZero = 0;
    int max = 147483647;
    int min = -147483648;

    for(int i = 0; i < length; i++){
        // havent entered digit segment yet
        if(positive == -1){
            // reach a negative sign first
            if(s[i] == 45) positive = 0;
            else if(s[i] == 43) positive = 1;
            else if(s[i] == 32) {}
            // reach a digit first, set positive to 1
            else if(48 <= s[i] && s[i] <= 57){
                positive = 1;
                // do not record 0
                if(s[i] != 48){
                    digits[pos] = s[i] - 48;
                    nonZero = 1;
                    pos++;
                    read++;
                }
            }

            // not a sign or digit, stop reading 
            else return 0;
        }
        // already in digit segment
        else{
            // record nonzero
            if(48 <= s[i] && s[i] <= 57){
                // read at most 10 digits
                if(pos == 10){
                    if(positive == 0) return -2147483648;
                    else return 2147483647;
                }
                // if there hasn't been a nonzero digit, dont read zero
                if(!nonZero && s[i] == 48){}
                else{
                    if(positive) digits[pos] = s[i] - 48;
                    else digits[pos] = 48 - s[i];
                    nonZero = 1;
                    pos++;
                    read++;
                }
            }else break;
        }
    }
    double k = 0.1;
    // tranfer array into int value
    for(int i = read - 1; i >= 0; i--){
        k *= 10;
        // reach the tenth digit
        if(read - 1 - i == 9){
            // out of range
            if(!positive){
                if(result < min){
                    if(digits[i] < -1) return -2147483648;
                }else{
                    if(digits[i] < -2) return -2147483648;
                }
            }else{
                if(result > max){
                    if(digits[i] > 1) return 2147483647;
                }else{
                    if(digits[i] > 2) return 2147483647;
                }
            }
        }
        // reach the tenth digit, break
        else if(read - 1 - i == 10){
            if(positive == 0) result = -2147483648;
            else result = 2147483647;
            break;
        }
        result += digits[i] * (int)k;
    }
    return result;
}
