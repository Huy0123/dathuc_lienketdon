#pragma once
class Element
{
private:
	float data;
	int exponent;
	Element* pointer;
public:
	int getData();
	void setData(int data);
	Element();
	~Element();
	Element* getPointer();
	void setPointer(Element* pointer);
	void setExponent(int exponent);
	int getExponent();
};

