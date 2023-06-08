#pragma once
#ifndef header_h
#define header_h

// Структура для узла в односвязном списке.
typedef struct Node {
    int data;           // Значение, хранящееся в узле.
    struct Node* next;  // Указатель на следующий узел в списке.
} Node;

// Структура для односвязного списка.
typedef struct LinkedList {
    Node* head;  // Указатель на начало списка.
    int length;  // Число элементов в списке.
} LinkedList;
#endif 
