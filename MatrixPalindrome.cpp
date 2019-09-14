#include <iostream>
using namespace std;

char * subRowCharArray(char source[], int offset, int length) {
    char *tmpCharArray = (char*)malloc(length * sizeof(char));
    for (int scpy = offset, sptr=0; sptr < length; scpy++, sptr++) {
        tmpCharArray[sptr] = source[scpy];
    }
    return tmpCharArray;
}

char * subColCharArray(char **source, int row, int offset, int length) {
    char *tmpCharArray = (char*)malloc(length * sizeof(char));
    for (int cs = offset; cs < offset + length; cs++) {
        for (int rs = row, sptr=0; rs < row + length; rs++, sptr++) {
            tmpCharArray[sptr] = source[rs][cs];
        }
    }
    return tmpCharArray;
}

bool isPalindrome(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;
 
    // Keep comparing characters while they are same
    while (end > start)
    {
        if (str[start++] != str[end--])
        {
            return false;
        }
    }
    return true;
}

bool isMatrixPalindrome(char **source, int row, int offset, int length) {
    // check all rows are palindrome;
    for (int rs = row; rs < row + length; rs++) {
        char *tmpCharArray = subRowCharArray(source[rs], offset, length);
        if (! isPalindrome(tmpCharArray)) {
            return false;
        }
    }

    // check all columns are palindrome
    for (int cs = offset; cs < offset + length; cs++) {
        char *tmpCharArray = (char*)malloc(length * sizeof(char));
        for (int rs = row, sptr=0; rs < row + length; rs++, sptr++) {
            tmpCharArray[sptr] = source[rs][cs];
        }
        if (! isPalindrome(tmpCharArray)) {
            return false;
        }
    }

    return true;
}

int main(){
    char **matrixCharArray;

    int rows,cols;

    // Take rows and column input
    cin >> rows >> cols;

    int upperLeftMostX = 1, upperLeftMostY = 1;
    int lowerRightMostX = rows, lowerRightMostY = cols;
    int palindromeSize = 1;

    // create 2D array for no of input rows
    matrixCharArray = (char **)malloc(sizeof(char*) * rows);

    if (rows >= 0 && rows <= 1000 && cols >= 0 && cols <= 1000) {
        for (int rs = 0; rs < cols; rs++) {
            // allocate memory for size of one column entry
            matrixCharArray[rs] = (char*)malloc(cols * sizeof(char));
            cin >> matrixCharArray[rs];
        }
    }

    int flag;
    // Search for upper leftmost corner palindrome.
    for (int rs = 0; rs < rows; rs++) {
        flag = 0;
        for (int cs = 0; cs < cols; cs++) {
            // states, we already largest possible uppermost leftmost palindrome matrix so continue with next row;
            if (flag == 1) {
                break;
            }
            for (int iter = 0; iter <= cs; iter++) {
                int length = cols - cs;
                char *tmpCharArray = subRowCharArray(matrixCharArray[rs], iter, length);
                if (isPalindrome(tmpCharArray)) {
                    if ((rs+length) <= rows && isMatrixPalindrome(matrixCharArray, rs, iter, length)) {
                        int size = length * length;
                        if (size > palindromeSize) {
                            palindromeSize = size;
                            upperLeftMostX = rs + 1;
                            upperLeftMostY = iter + 1;
                            lowerRightMostX = rs + length;
                            lowerRightMostY = iter + length;
                        }
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
    
    cout << upperLeftMostX << " " << upperLeftMostY << " " << lowerRightMostX << " " << lowerRightMostY; 
    return 0;
}