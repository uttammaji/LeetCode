#include <iostream>
using namespace std;

int main() {
    int n = 7789;
    int reversed_num = 0;

    while (n > 0) {
        int lastdigit = n % 10;                // 1. Extract the last digit
        reversed_num = (reversed_num * 10) + lastdigit; // 2. Shift left and add digit
        n = n / 10;                            // 3. Remove the last digit from n
    }

    cout << "Reversed Number: " << reversed_num << endl;

    return 0;
}
