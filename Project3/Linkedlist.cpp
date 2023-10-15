#include "Linkedlist.h"

Linkedlist::Linkedlist()
{
	this->head = nullptr;
	this->tail = nullptr;
}

Linkedlist::~Linkedlist()
{
}

void Linkedlist::addHead(Element* a)
{
	if (this->head == nullptr) {
		this->head = this->tail = a;
	}
	else {
		a->setPointer(this->head);
		this->head = a;
	}
}

void Linkedlist::display()
{
	Element* p = this->head;
	while (p != nullptr) {
		std::cout << p->getData() << " ";
		p = p->getPointer();
	}
}

int Linkedlist::Sumlist()
{
	Element* p = this->head;
	int sum=0;
	while (p != nullptr) {
		sum += p->getData();
		p = p->getPointer();
	}
	return sum;
}

int Linkedlist::Maxlist()
{
	Element* p = this->head;
	int max = 0;
	while (p != nullptr) {
		if (p->getData() > max) {
			max = p->getData();
		}
		p = p->getPointer();
	}
	return max;
}

int Linkedlist::Countlist()
{
	Element* p = this->head;
	int count = 0;
	while (p != nullptr) {
		count++;
		p = p->getPointer();
	}
	return count;
}

void Linkedlist::addTail(Element* a)
{
	if (this->head == nullptr) {
		this->head = this->tail = a;
	}
	else{
		this->tail->setPointer(a);
		this->tail = a;
	}
}

void Linkedlist::DeleteHead()
{
	Element* p = head;
	this->head = this->head->getPointer();
	delete p;
}

void Linkedlist::DeleteTail()
{
	Element* p = head;
	while (p->getPointer()!=tail)
	{
		p = p->getPointer();
	}
	delete tail;
	tail = p;
	tail->setPointer(nullptr);
}

int Linkedlist::FindX(int x)
{
	Element* p = head;
	int count = 0;
	while (p!=nullptr)
	{
		if (p->getData() == x) {
			count++;
		}
		p = p->getPointer();
	}
	return count;
}

bool Linkedlist::kiemtra_trung(int x)
{
	Element* p = head;
	while (p!=nullptr)
	{
		if (p->getData() == x) {
			return true;
		}
		else return false;
		p = p->getPointer();
	}
}

void Linkedlist::splitLinkedlist(Linkedlist*& a, Linkedlist*& b, int x)
{
	Element* p = head;

	while (p != nullptr) {
		if (p->getData() > x) {
				a->addTail(p);
		}
		else {
				b->addTail(p);
		}

		p = p->getPointer();
	}

	a->tail->setPointer(nullptr);
	b->tail->setPointer(nullptr);
	head = tail = nullptr;
}

void Linkedlist::addMiddle(Element* p, Element* data)
{
	data->setPointer(p->getPointer());
	p->setPointer(data);
}

void Linkedlist::DeleteMiddle(Element*p)
{
	Element* q = head;
	while (q->getPointer() != p) {
		q = q->getPointer();
	}
	q->setPointer(p->getPointer());
	delete p;
}

void Linkedlist::nhap()
{
	int n, y;
	float x;
	std::cout << "Nhap so luong phan tu cua da thuc: ";
	std::cin >> n;

	std::cout << "Nhap he so va so mu cho tung hang tu:" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "He so: ";
		std::cin >> x;
		std::cout << "So mu: ";
		std::cin >> y;

		Element* a = new Element();
		a->setData(x);
		a->setExponent(y);
		addTail(a); // Thêm hạng tử vào danh sách liên kết kép
	}
}

Linkedlist* Linkedlist::add(Linkedlist* a)
{
	Linkedlist* sum = new Linkedlist();
	Element* p = this->head;
	Element* q = a->head;

	while (p != nullptr && q != nullptr) {
		// Tạo một đối tượng ElementDual mới cho mỗi phần tử kết quả
		Element* resultElement = new Element();

		if (p->getExponent() == q->getExponent()) {
			resultElement->setData(p->getData() + q->getData());
			resultElement->setExponent(p->getExponent());
			p = p->getPointer();
			q = q->getPointer();
		}
		else if (p->getExponent() > q->getExponent()) {
			resultElement->setData(p->getData());
			resultElement->setExponent(p->getExponent());
			p = p->getPointer();
		}
		else {
			resultElement->setData(q->getData());
			resultElement->setExponent(q->getExponent());
			q = q->getPointer();
		}

		sum->addTail(resultElement); // Thêm đối tượng mới vào danh sách kết quả
	}
	// Xử lý các phần tử còn lại nếu có

	while (p != nullptr) {
		Element* resultElement = new Element();
		resultElement->setData(p->getData());
		resultElement->setExponent(p->getExponent());
		sum->addTail(resultElement);
		p = p->getPointer();
	}

	while (q != nullptr) {
		Element* resultElement = new Element();
		resultElement->setData(q->getData());
		resultElement->setExponent(q->getExponent());
		sum->addTail(resultElement);
		q = q->getPointer();
	}

	return sum;

}
Linkedlist* Linkedlist::multiply(Linkedlist* a)
{
	Linkedlist* b = new Linkedlist();
	Element* p = this->head;
	Element* q = a->head;

	while (p != nullptr) {
		while (q != nullptr) {
			Element* tmp = new Element();
			tmp->setData(p->getData() * q->getData());
			tmp->setExponent(p->getExponent() + q->getExponent());
			b->addTail(tmp);
			q = q->getPointer();
		}
		q = a->head; // Đặt lại con trỏ q cho vòng lặp ngoài cùng
		p = p->getPointer();
	}

	// Sao chép các phần tử còn lại từ danh sách gốc
	while (p != nullptr) {
		Element* tmp = new Element();
		tmp->setData(p->getData());
		tmp->setExponent(p->getExponent());
		b->addTail(tmp);
		p = p->getPointer();
	}

	while (q != nullptr) {
		Element* tmp = new Element();
		tmp->setData(q->getData());
		tmp->setExponent(q->getExponent());
		b->addTail(tmp);
		q = q->getPointer();
	}

	b->rutgon();
	return b;
}

void Linkedlist::rutgon()
{
	Element* current = head;
	while (current != nullptr) {
		Element* next = current->getPointer();
		while (next != nullptr) {
			if (current->getExponent() == next->getExponent()) {
				current->setData(current->getData() + next->getData());
				// Loại bỏ hạng tử next sau khi đã cộng
				DeleteMiddle(next);
				next = current->getPointer(); // Di chuyển next đến phần tử tiếp theo
			}
			else {
				next = next->getPointer();
			}
		}
		current = current->getPointer();
	}
}

double Linkedlist::evaluate(int inputValue)
{
	double value = 0.0;
	Element* p = head;

	while (p != nullptr) {
		value += p->getData() * pow(inputValue, p->getExponent());
		p = p->getPointer(); // Di chuyển đến phần tử tiếp theo trong danh sách
	}

	return value;
}


