#include <stdio.h>
#include <string.h>
char *infinite_add(char *n1, char *n2, char *r, int size_r);
char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int carry = 0;
    int index_n1 = strlen(n1) - 1;
    int index_n2 = strlen(n2) - 1;
    int index_r = size_r - 2;  // Reserve last character for null terminator
    while (index_n1 >= 0 || index_n2 >= 0) {
        int digit_n1 = (index_n1 >= 0) ? n1[index_n1] - '0' : 0;
        int digit_n2 = (index_n2 >= 0) ? n2[index_n2] - '0' : 0;
        int sum = digit_n1 + digit_n2 + carry;
        carry = sum / 10;
        int digit_sum = sum % 10;
        if (index_r < 0) {
            return 0;  // Result can't be stored in r
        }
        r[index_r] = digit_sum + '0';
        index_n1--;
        index_n2--;
        index_r--;
    }
    if (carry > 0 && index_r >= 0) {
        r[index_r] = carry + '0';
        index_r--;
    }
    if (index_r < 0) {
        return 0;  // Result can't be stored in r
    }

    // Shift the result to the beginning of the buffer
    memmove(r, r + index_r + 1, size_r - index_r);

    return r;
}

int main() {
    char n1[] = "12345";
    char n2[] = "67890";
    int size_r = sizeof(n1) + sizeof(n2) + 1;  // Buffer size for result (+1 for null terminator)
    char r[size_r];

    char *result = infinite_add(n1, n2, r, size_r);
    if (result != 0) {
        printf("Result: %s\n", result);
    } else {
        printf("Result cannot be stored in r.\n");
    }

    return 0;
}
