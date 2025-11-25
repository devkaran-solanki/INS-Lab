#include <stdio.h>
#include <string.h>

#define KEY 127   // constant value for AND/XOR operations

int main() {
    char input[256];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline if present
    input[strcspn(input, "\n")] = '\0';

    char and_result[256];
    char xor_result[256];

    // Apply operations
    for (int i = 0; input[i] != '\0'; i++) {
        and_result[i] = input[i] & KEY;
        xor_result[i] = input[i] ^ KEY;
    }

    // Null-terminate results
    and_result[strlen(input)] = '\0';
    xor_result[strlen(input)] = '\0';

    // Print results
    printf("\nOriginal:   %s\n", input);
    printf("AND 127:    ");

    for (int i = 0; and_result[i] != '\0'; i++)
        printf("%02X ", (unsigned char)and_result[i]);  // show hex values

    printf("\nXOR 127:    ");

    for (int i = 0; xor_result[i] != '\0'; i++)
        printf("%02X ", (unsigned char)xor_result[i]);

    printf("\n");

    return 0;
}
