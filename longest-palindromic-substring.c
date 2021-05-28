/**
 * Author: Shaoqian Zhou
 * Date: Mar. 27th 2021
 */

int longestLeft;
int longestRight;
char * longestPalindrome(char * s){
    // find the middle position of the string
    int length = strlen(s);
    int mid = length/2;
    // set this single char as longest palindrome
    longestLeft = mid;
    longestRight = mid;
    // printf("%d", mid);
    // left half of the string
    for(int i = mid; i > 0; i--){
        if(s[i] == s[i-1])
            isPalindrome(s, i-1, i, length);
        isPalindrome(s, i, i, length);
    }
    // right half of the string
    for(int i = mid+1; i < length; i++){
        if(s[i] == s[i-1])
            isPalindrome(s, i-1, i, length);
        isPalindrome(s, i, i, length);
    }
    
    int palindromeLength = longestRight - longestLeft + 1;
    //printf("%d\n", palindromeLength);
    // allocate memory for this new substring
    char *r = malloc(palindromeLength + 1);
    for(int i = 0; i < palindromeLength; i++)
        r[i] = s[longestLeft + i];
    r[palindromeLength] = '\0';
    return r;
}

void isPalindrome(char *s, int lpos, int rpos, int length){
    //printf("Testing\n");
    // if the extended string is not palindromic anymore, or it has exceeded the given string
    if(lpos < 0 || rpos > length - 1 || s[lpos] != s[rpos])
        return;
    // the extended string remains palindromic
    else{
        // if this extended string is longer than the current record, replace it
        if((rpos - lpos) > (longestRight - longestLeft)){
            longestLeft = lpos;
            longestRight = rpos;
        }
        // extend the string to left and right each by 1 char
        isPalindrome(s, lpos-1, rpos+1, length);
    }
}
