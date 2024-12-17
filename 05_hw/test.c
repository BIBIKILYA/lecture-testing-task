/*#include "stack.h"
#include <assert.h>
#include <stdio.h>

// ������ ��� ������ �����������
#define PASS(msg) printf("%s - PASSED\n", msg)

// ������� ����� (��� ���������)
void testPushToStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    assert(!isEmpty(&stack));
    assert(getTop(&stack)->data == 10);

    push(&stack, 20);
    assert(getTop(&stack)->data == 20);

    PASS("Push to stack");
}

void testPopFromStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);

    pop(&stack);
    assert(getTop(&stack)->data == 10);

    pop(&stack);
    assert(isEmpty(&stack));

    PASS("Pop from stack");
}

void testIsEmpty() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack));
    push(&stack, 10);
    assert(!isEmpty(&stack));

    PASS("isEmpty");
}

void testDestroyStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    destroyStack(&stack);

    assert(isEmpty(&stack));

    PASS("Destroy stack");
}

void testGetTopEmptyStack() {
    Stack stack;
    initStack(&stack);

    assert(getTop(&stack) == NULL);

    PASS("Get top on empty stack");
}

void testTraverseStack() {
    Stack stack;
    initStack(&stack);

    printf("Expected output: (nothing)\n");
    printf("Actual output: ");
    traverseStack(&stack);
    printf("\n");

    push(&stack, 10);
    push(&stack, 20);

    printf("Expected output: 20 10\n");
    printf("Actual output: ");
    traverseStack(&stack);
    printf("\n");

    PASS("Traverse stack");
}

void testSearchByIndex() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByIndex(&stack, 1);
    assert(result != NULL && result->data == 20);

    result = searchByIndex(&stack, 5);
    assert(result == NULL);

    PASS("Search by index");
}

void testSearchByValue() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByValue(&stack, 20);
    assert(result != NULL && result->data == 20);

    result = searchByValue(&stack, 50);
    assert(result == NULL);

    PASS("Search by value");
}

// ����� �����: ���������� ��������
void testInitStackMultipleNull() {
    for (int i = 0; i < 5; ++i) {
        initStack(NULL); // ��������� ������ 20
    }
    PASS("Multiple initStack with NULL");
}

void testIsEmptyMultipleNull() {
    for (int i = 0; i < 5; ++i) {
        assert(isEmpty(NULL) == true); // ��������� ������ 29
    }
    PASS("Multiple isEmpty with NULL");
}

void testPushMultipleNull() {
    for (int i = 0; i < 5; ++i) {
        push(NULL, i); // ��������� ������ 38
    }
    PASS("Multiple push with NULL");
}

void testCombinedNullOperations() {
    initStack(NULL);
    assert(isEmpty(NULL) == true);
    push(NULL, 10);
    pop(NULL);
    destroyStack(NULL); // ����� ������� � NULL ��� ���� �������
    PASS("Combined operations with NULL");
}

// �������� ������� ������� ������
int main() {
    // ������� �����
    testPushToStack();
    testPopFromStack();
    testIsEmpty();
    testDestroyStack();
    testGetTopEmptyStack();
    testTraverseStack();
    testSearchByIndex();
    testSearchByValue();

    // ����� ����� ��� ���������� ��������
    testInitStackMultipleNull();
    testIsEmptyMultipleNull();
    testPushMultipleNull();
    testCombinedNullOperations();

    printf("All tests passed successfully!\n");
    return 0;
}
*/

#include "stack.h"
#include <assert.h>
#include <stdio.h>

void test_push_null_stack() {
    push(NULL, 10);
    printf("Test: push with NULL stack - PASSED\n");
}

void test_pop_null_stack() {
    pop(NULL);
    printf("Test: pop with NULL stack - PASSED\n");
}

void test_destroyStack_null_stack() {
    destroyStack(NULL);
    printf("Test: destroyStack with NULL stack - PASSED\n");
}

void test_initStack_null() {
    initStack(NULL);
    printf("Test: initStack with NULL - PASSED\n");
}

void test_destroyStack_non_empty() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    destroyStack(&stack);
    assert(stack.top == NULL);

    printf("Test: destroyStack on non-empty stack - PASSED\n");
}

void test_getTop_non_empty_stack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);

    Node* top = getTop(&stack);
    assert(top != NULL && top->data == 20);

    printf("Test: getTop on non-empty stack - PASSED\n");
}

void test_getTop_empty_stack() {
    Stack stack;
    initStack(&stack);

    Node* top = getTop(&stack);
    assert(top == NULL);

    printf("Test: getTop on empty stack - PASSED\n");
}

void test_traverseStack_empty() {
    Stack stack;
    initStack(&stack);

    printf("Expected output: (nothing)\n");
    printf("Actual output: ");
    traverseStack(&stack);

    printf("Test: traverseStack on empty stack - PASSED\n");
}

void test_traverseStack_non_empty() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Expected output: Stack elements: 30 20 10\n");
    printf("Actual output: ");
    traverseStack(&stack);

    printf("Test: traverseStack on non-empty stack - PASSED\n");
}

void test_searchByIndex() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByIndex(&stack, 1);
    assert(result != NULL && result->data == 20);

    result = searchByIndex(&stack, 5);
    assert(result == NULL);

    printf("Test: searchByIndex - PASSED\n");
}

void test_isEmpty() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);

    push(&stack, 10);
    assert(isEmpty(&stack) == false);

    pop(&stack);
    assert(isEmpty(&stack) == true);

    printf("Test: isEmpty - PASSED\n");
}

void test_searchByValue_null_stack() {
    Node* result = searchByValue(NULL, 10);
    assert(result == NULL);
    printf("Test: searchByValue with NULL stack - PASSED\n");
}

void test_searchByValue_empty_stack() {
    Stack stack;
    initStack(&stack);

    Node* result = searchByValue(&stack, 10);
    assert(result == NULL);
    printf("Test: searchByValue on empty stack - PASSED\n");
}

void test_searchByValue_existing_value() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByValue(&stack, 20);
    assert(result != NULL && result->data == 20);
    printf("Test: searchByValue with existing value - PASSED\n");
}

void test_searchByValue_non_existing_value() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByValue(&stack, 40);
    assert(result == NULL);
    printf("Test: searchByValue with non-existing value - PASSED\n");
}


void test_createNode_null() {
    Node* node = createNode(10);
    assert(node != NULL);
    printf("Test: createNode handles memory allocation successfully - PASSED\n");
}

void test_push_memory_failure() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    assert(stack.top != NULL);
    printf("Test: push handles memory allocation successfully - PASSED\n");
}


void test_searchByIndex_null_stack() {
    Node* result = searchByIndex(NULL, 0);
    assert(result == NULL);
    printf("Test: searchByIndex with NULL stack - PASSED\n");
}


void test_traverseStack_null_stack() {
    traverseStack(NULL);
    printf("Test: traverseStack with NULL stack - PASSED\n");
}

int main() {

    test_push_null_stack();
    test_pop_null_stack();
    test_destroyStack_null_stack();
    test_initStack_null();

    test_destroyStack_non_empty();
    test_getTop_non_empty_stack();
    test_getTop_empty_stack();
    test_traverseStack_empty();
    test_traverseStack_non_empty();
    test_searchByIndex();
    test_isEmpty();

    test_searchByValue_null_stack();
    test_searchByValue_empty_stack();
    test_searchByValue_existing_value();
    test_searchByValue_non_existing_value();

    test_createNode_null();
    test_push_memory_failure();

    test_searchByIndex_null_stack();
    test_traverseStack_null_stack();

    printf("All tests passed successfully!\n");
    return 0;
}