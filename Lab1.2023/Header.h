#pragma once
#ifndef header_h
#define header_h

// ��������� ��� ���� � ����������� ������.
typedef struct Node {
    int data;           // ��������, ���������� � ����.
    struct Node* next;  // ��������� �� ��������� ���� � ������.
} Node;

// ��������� ��� ������������ ������.
typedef struct LinkedList {
    Node* head;  // ��������� �� ������ ������.
    int length;  // ����� ��������� � ������.
} LinkedList;
#endif 
