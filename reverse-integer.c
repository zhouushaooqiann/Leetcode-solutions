/**
 * Author: Shaoqian Zhou
 * Date: Mar. 27th 2021
 */

int reverse(int x){
    // array storing
    int digits[10];
    int i = 1;
    int digit = 0;
    int lowNonzero = -1;
    int highNonzero = -1;

    // get first 9 digits
    for(int num = 0; num < 9; num++){
        i *= 10;

        // get this digit
        digit = (x % i - x % (i / 10)) / (i / 10);

        // if non-zero
        if(digit != 0){
            // if this is the lowest digit, update lowNonzero
            if(lowNonzero == -1) lowNonzero = num;

            // keep updating highNonzero if digit is non-zero
            highNonzero = num;
        }
        
        // record the digit
        digits[num] = digit;
    }

    // get the 10th digit
    digit = (x - x % i) / i;
    if(digit != 0){
        // if this is the lowest digit, update lowNonzero
        if(lowNonzero == -1) lowNonzero = 9;
    
        // keep updating highNonzero if digit is non-zero
        highNonzero = 9;
    }
    digits[9] = digit;

    int result = 0;

    if(lowNonzero == -1) return 0;
    i = 1;
    
    // revert the int
    for(int num = highNonzero; num >= lowNonzero; num--){
        // if this is the tenth digit
        if(highNonzero - num == 9){
            if(result > 147483647 || result < -147483648){
                if(digits[num] < 2 && -2 < digits[num])
                    result += digits[num] * i;
                else return 0;
            }
            else{
                if(digits[num] <= 2 && -2 <= digits[num])
                    result += digits[num] * i;
                else return 0;
            }
        
        }
        else{
            result += digits[num] * i;
            i *= 10;
        }
    }
    
    return result;
}
