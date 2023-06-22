#include <stdio.h>
#include <string.h>10
#include <math.h>

int main() {
    int n;
    char s[20];

    // Read inputs
    printf("Enter the length of binary strings (n): ");
    scanf("%d", &n);
    printf("Enter the substring (s): ");
    scanf("%s", s);

    int len_s = strlen(s);

    // Calculate the count of substrings
    int count_subs = pow(2, len_s) - 2 - (len_s - 1);

    // Calculate the count of valid binary strings
    int count_valid = pow(2, n) - count_subs;

    printf("Count: %d\n", count_valid);

    return 0;
}
