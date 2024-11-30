// Form Alternating string
#include <stdio.h>
#include <string.h>

int main() {
    char binaryString[10001];
    int worth[10001];
    int n;

    scanf("%s", binaryString);
    n = strlen(binaryString);

    for (int i = 0; i < n; i++) {
        scanf("%d", &worth[i]);
    }

    char lastChar = '\0'; 
    int lastWorth = 0; 
    int removedWorth = 0; 

    for (int i = 0; i < n; i++) {
        if (binaryString[i] != lastChar) {
            lastChar = binaryString[i];
            lastWorth = worth[i];
        } else {
            if (worth[i] > lastWorth) {
                removedWorth += lastWorth;
                lastChar = binaryString[i];
                lastWorth = worth[i];
            } else {
                removedWorth += worth[i];
            }
        }
    }

    printf("%d", removedWorth);  

    return 0;
}