#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define maximum stack size

// Stack structure definition
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void init(Stack* s) {
    s->top = -1;  // Set top to -1 indicating the stack is empty
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to push an item onto the stack
void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack is full, cannot push %d\n", item);
        return;
    }
    s->items[++(s->top)] = item;  // Increment top and add the item
}

// Function to pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot pop\n");
        exit(1);  // Exit program if pop is attempted on an empty stack
    }
    return s->items[(s->top)--];  // Return the top item and decrement top
}

// Function to calculate factorial using stack
int factorial(int n) {
    Stack s;
    init(&s);
    int result = 1;

    // Push all numbers from n down to 1 onto the stack
    for (int i = n; i > 0; i--) {
        push(&s, i);
    }

    // Pop numbers from the stack and multiply
    while (!isEmpty(&s)) {
        result *= pop(&s);
    }

    return result;
}

// Main function
int main() {
    int number;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    // Check for invalid input
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %d\n", number, factorial(number));
    }

    return 0;
}
