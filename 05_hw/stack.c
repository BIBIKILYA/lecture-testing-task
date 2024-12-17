#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Создание нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Инициализация стека
void initStack(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot initialize a NULL stack\n");
        return;
    }
    stack->top = NULL;
}

// Проверка, пуст ли стек
bool isEmpty(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot check isEmpty on a NULL stack\n");
        return true;
    }
    return stack->top == NULL;
}

// Добавление элемента в стек
void push(Stack* stack, int data) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot push to a NULL stack\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Удаление элемента из стека
void pop(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot pop from a NULL stack\n");
        return;
    }
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

// Очистка стека
void destroyStack(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot destroy a NULL stack\n");
        return;
    }
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
}

// Получение верхнего элемента стека
Node* getTop(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot get top of a NULL stack\n");
        return NULL;
    }
    return stack->top;
}

// Перебор элементов стека
void traverseStack(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot traverse a NULL stack\n");
        return;
    }
    printf("Stack elements: ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Поиск элемента по значению
Node* searchByValue(Stack* stack, int value) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot search in a NULL stack\n");
        return NULL;
    }
    Node* current = stack->top;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Поиск элемента по индексу
Node* searchByIndex(Stack* stack, int index) {
    if (stack == NULL) {
        fprintf(stderr, "Cannot search by index in a NULL stack\n");
        return NULL;
    }
    Node* current = stack->top;
    int i = 0;
    while (current != NULL) {
        if (i == index) {
            return current;
        }
        current = current->next;
        i++;
    }
    return NULL;
}
