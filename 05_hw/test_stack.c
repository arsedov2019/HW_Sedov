
#include <stdio.h>
#include <assert.h>
#include "stack.h"

void test_init_destroy_stack() {
    Stack stack;
    initStack(&stack);
    assert(isEmpty(&stack) == true);
    destroyStack(&stack);
    printf("test_init_destroy_stack passed\n");
}

void test_push_pop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    assert(getTop(&stack)->data == 10);
    push(&stack, 20);
    assert(getTop(&stack)->data == 20);
    push(&stack, 30);
    assert(getTop(&stack)->data == 30);

    pop(&stack);
    assert(getTop(&stack)->data == 20);
    pop(&stack);
    assert(getTop(&stack)->data == 10);
    pop(&stack);
    assert(isEmpty(&stack) == true);

    destroyStack(&stack);
    printf("test_push_pop passed\n");
}

void test_searchByValue() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    assert(searchByValue(&stack, 20)->data == 20);
    assert(searchByValue(&stack, 40) == NULL);

    destroyStack(&stack);
    printf("test_searchByValue passed\n");
}

void test_searchByIndex() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    assert(searchByIndex(&stack, 0)->data == 30);
    assert(searchByIndex(&stack, 1)->data == 20);
    assert(searchByIndex(&stack, 2)->data == 10);
    assert(searchByIndex(&stack, 3) == NULL);

    destroyStack(&stack);
    printf("test_searchByIndex passed\n");
}

void test_isEmpty() {
    Stack stack;
    initStack(&stack);
    assert(isEmpty(&stack) == true);

    push(&stack, 10);
    assert(isEmpty(&stack) == false);

    pop(&stack);
    assert(isEmpty(&stack) == true);

    destroyStack(&stack);
    printf("test_isEmpty passed\n");
}

void test_traverseStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Expected output: Stack elements: 30 20 10\nActual output: ");
    traverseStack(&stack);

    destroyStack(&stack);
    printf("test_traverseStack passed\n");
}

int main() {
    test_init_destroy_stack();
    test_push_pop();
    test_searchByValue();
    test_searchByIndex();
    test_isEmpty();
    test_traverseStack();

    printf("All tests passed!\n");
    return 0;
}
