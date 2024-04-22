#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    char stack[1000]; 
    int top = -1; 
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i]; 
        } else {
            if (top == -1) {
                return false; 
            } else if ((s[i] == ')' && stack[top] != '(') ||
                       (s[i] == '}' && stack[top] != '{') ||
                       (s[i] == ']' && stack[top] != '[')) {
                return false; 
            } else {
                top--; 
            }
        }
    }
    
    return top == -1;
}

int main() {
    char input[1000];
    printf("Enter a string containing only '(', ')', '{', '}', '[' and ']': ");
    scanf("%s", input);

    if (isValid(input)) {
        printf("The input string is valid.\n");
    } else {
        printf("The input string is not valid.\n");
    }

    return 0;
}
