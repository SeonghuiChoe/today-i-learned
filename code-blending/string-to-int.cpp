/**
 * 2017-02-17
 * 문자열을 숫자로 파싱
 */
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int n = 0;
    int result = 0;
    while (argv[1][n] != '\0') {
        result *= 10;
        switch (argv[1][n]) {
            case '1' : result += 1; break;
            case '2' : result += 2; break;
            case '3' : result += 3; break;
            case '4' : result += 4; break;
            case '5' : result += 5; break;
            case '6' : result += 6; break;
            case '7' : result += 7; break;
            case '8' : result += 8; break;
            case '9' : result += 9; break;
        }
        n++;
    }

    if (argv[1][0] == '-') result *= -1;
    cout << result << endl;
    return 0;
}

