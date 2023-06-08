#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include "header.h"

// Функция для вставки элемента в указанную позицию списка.
// Если указанная позиция больше длины списка, элемент добавляется в конец списка.
void insert(LinkedList* list, int index, int value) {
    // Создаем новый узел и инициализируем его значениями.
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    Node* current = list->head;
    
    // Если индекс меньше или равен нулю, добавляем элемент в начало списка.
    if (index <= 0) {
        new_node->next = list->head;
        list->head = new_node;
    }
    else {
        // В противном случае идем по списку до указанной позиции и вставляем там элемент.
        for (int i = 0; i < index - 1; i++) {
            if (current->next == NULL) break;
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    // Увеличиваем длину списка на 1.
    list->length++;
}

// Функция для получения значения элемента по указанному индексу.
// Если указанный индекс больше длины списка, возвращается -1.
int getValue(LinkedList* list, int index) {
    Node* current = list->head;

    // Идем по списку до указанного индекса.
    for (int i = 0; i < index; i++) {
        if (current->next == NULL) return -1;
        current = current->next;
    }

    // Возвращаем значение в указанной позиции.
    return current->data;
}

// Функция для получения адреса элемента по указанному индексу.
// Если указанный индекс больше длины списка, возвращается NULL.
Node* getAddress(LinkedList* list, int index) {
    Node* current = list->head;

    // Идем по списку до указанного индекса.
    for (int i = 0; i < index; i++) {
        if (current->next == NULL) return NULL;
        current = current->next;
    }

    // Возвращаем адрес узла в указанной позиции.
    return current;
}
// Функция для удаления элемента в указанной позиции.
// Если указанный индекс больше длины списка, ничего не происходит.
void deleteNode(LinkedList* list, int index) {
    Node* current = list->head;
    Node* previous = NULL;

    // Если индекс меньше или равен нулю и список не пуст,
    // удаляем первый элемент списка.
    if (index <= 0 && list->head != NULL) {
        list->head = list->head->next;
        free(current);
    }
    else {
        // В противном случае идем по списку до указанной позиции
        // и удаляем узел на этой позиции.
        for (int i = 0; i < index; i++) {
            if (current->next == NULL) return;
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        free(current);
    }

    // Уменьшаем длину списка на 1.
    list->length--;
}


// Функция для подсчета количества элементов в списке.
int count(LinkedList* list) {
    return list->length;
}

// Функция для подсчета количества элементов, значения которых
// совпадают со значениями первого или последнего элемента списка.
int countFirstLastEqual(LinkedList* list) {
    // Если список пуст или содержит только один элемент,
    // возвращаем текущую длину списка.
    if (list->head == NULL || list->head->next == NULL) {
        return list->length;
    }

    int firstValue = list->head->data;
    Node* current = list->head;

    // Ищем последний элемент списка.
    while (current->next != NULL) {
        current = current->next;
    }

    int lastValue = current->data;

    current = list->head->next;
    int count = 0;

    // Идем по списку и считаем количество элементов,
    // значения которых совпадают с первым или последним элементом.
    while (current->next != NULL) {
        if (current->data == firstValue || current->data == lastValue) {
            count++;
        }
        current = current->next;
    }

    return count;
}

int contains(LinkedList* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

LinkedList* intersect(LinkedList* list1, LinkedList* list2) {
    // Создаем новый список.
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->length = 0;

    Node* current1 = list1->head;

    // Идем по первому списку.
    while (current1 != NULL) {
        Node* current2 = list2->head;

        // Идем по второму списку.
        while (current2 != NULL) {
            // Если находим общий элемент и его нет в newList, добавляем его в новый список.
            if (current1->data == current2->data && !contains(newList, current1->data)) {
                insert(newList, newList->length, current1->data);
                break;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    // Возвращаем новый список.
    return newList;
}


// Функция для вывода списка на экран.
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    setlocale(0, "RUS");
    srand(time(NULL));
    // Создаем новый список.
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->length = 0;

    // Добавляем случайное количество элементов в список.
    for (int i = 0; i < 8; i++) {
        insert(list, i, rand() % 10);  // случайное число от 0 до 9.
       
    }
    printList(list);
    // Определяем количество элементов в списке, значения которых совпадают со значениями первого или последнего элемента.
    int count1 = countFirstLastEqual(list);
    printf("Количество элементов, совпадающих с первым или последним элементом: %d\n", count1);
        // Создаем списки L1 и L2.
        LinkedList* L1 = (LinkedList*)malloc(sizeof(LinkedList));
        L1->head = NULL;
        L1->length = 0;

        LinkedList* L2 = (LinkedList*)malloc(sizeof(LinkedList));
        L2->head = NULL;
        L2->length = 0;

        // Добавляем случайные элементы в списки L1 и L2.
        for (int i = 0; i < 5; i++) {
            insert(L1, i, rand() % 10);  // случайное число от 0 до 9.
            insert(L2, i, rand() % 10);
        }
        // Выводим количество элементов в списке.
        printf("Изначальное кол-во элементов в списке: %d\n", count(L1));
        // Выводим списки L1 и L2.
        printf("L1: ");
        printList(L1);

        printf("L2: ");
        printList(L2);

        
        // Создаем список L3 как пересечение L1 и L2.
        LinkedList* L3 = intersect(L1, L2);

        // Выводим список L3.
        printf("L3: ");
        printList(L3);

    // Удаляем элемент из списка.
    deleteNode(list, 1);

    // Выводим количество элементов в списке после удаления.
    printf("Кол-во элементов после удаления: %d\n", count(L3));

    return 0;
}

