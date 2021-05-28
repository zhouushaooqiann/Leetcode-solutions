/**
 * Author: Shaoqian Zhou
 * Date: Mar. 27th 2021
 */

char * convert(char * s, int numRows){
    // get the length of string
    int length = strlen(s);
    
    // allocate memory
    char *result = malloc(length + 1);

    // # of bytes for each repeatition
    int eachRepeat;
    if(numRows == 1) eachRepeat = 1;
    else eachRepeat = numRows + numRows - 2;

    // get # of unit repeatition
    int numRepeat = length/eachRepeat;

    // iteratively print all repeat units
    int numRead = 0;
    for(int i = 0; i < numRows; i++){
        // discuss different cases
        // case 1: first row, only one byte
        if(i == 0){
            int rowRead = 0;
            for(int k = 0; k <= numRepeat; k++){
                if(k*eachRepeat < length){
                    result[k] = s[k*eachRepeat];
                    rowRead++;
                }
            }
            // update numRead
            numRead += rowRead;
        }
        // case 2: last row, only one byte as well
        else if(i == numRows - 1){
            for(int k = 0; k <= numRepeat; k++){
                if(k*eachRepeat + numRows - 1 < length) result[k + numRead] = s[k*eachRepeat + numRows - 1];
            }
        }
        // case 3: any row between the first and last, two bytes
        else{
            // keep in track of #bytes read this row
            int rowRead = 0;
            for(int k = 0; k <= numRepeat; k++){
                // print left byte first
                if(k*eachRepeat + i < length){
                    result[2*k + numRead] = s[k*eachRepeat + i];
                    rowRead++;
                }
                // print right byte
                if(k*eachRepeat + eachRepeat - i < length){
                    result[2*k + 1 + numRead] = s[k*eachRepeat + eachRepeat - i];
                    rowRead++;
                }
            }
            numRead += rowRead;
        }
    }
    // end the result string
    result[length] = '\0';
    return result;
}
