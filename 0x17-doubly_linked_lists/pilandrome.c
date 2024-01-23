#include <stdio.h>
#include <string.h>

int is_palindrome(int n) {
    char str[10];
    sprintf(str, "%d", n);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int largest_palindrome = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (product < largest_palindrome) {
                break;
            }
            if (is_palindrome(product)) {
                largest_palindrome = product;
            }
        }
    }
    char result[10];
    sprintf(result, "%d", largest_palindrome);
    result[6] = '\0'; // remove the trailing newline character
    FILE *f = fopen("102-result", "w");
    fprintf(f, "%s", result);
    fclose(f);
    return 0;
}
