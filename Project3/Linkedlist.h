#pragma once
#include"Element.h"
#include<iostream>
class Linkedlist
{
private:
	Element* head;
	Element* tail;

public:
	Linkedlist();
	~Linkedlist();
	void addHead(Element*);
	void display();
	int Sumlist();
	int Maxlist();
	int Countlist();
	void addTail(Element*);
	void DeleteHead();
	void DeleteTail();
	int FindX(int x);
	bool kiemtra_trung(int x);
	void splitLinkedlist(Linkedlist*& a, Linkedlist*& b, int x);
	void addMiddle(Element* p, Element* data);
	void DeleteMiddle(Element*);
	void nhap();
	Linkedlist* add(Linkedlist* a);
	Linkedlist* multiply(Linkedlist* a);
	void rutgon();
	double evaluate(int inputValue);
};

