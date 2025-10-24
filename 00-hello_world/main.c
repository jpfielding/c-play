#include <stdio.h>

int main()
{

    printf("Hello World!\n");

    char name[25]; //bytes
    int age;

    printf("Enter your name: ");
    // scanf("%24s", name); //limit input to avoid overflow
    fgets(name, sizeof(name), stdin); // safer way to read strings
    name[strcspn(name, "\n")] = 0; // remove newline character
    
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Hello %s, you are %d years old!\n", name, age);

    return 0;
}