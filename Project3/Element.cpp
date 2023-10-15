#include "Element.h"

int Element::getData()
{
    return this->data;
}

void Element::setData(int data)
{
    this->data = data;
}

Element::Element()
{
}



Element::~Element()
{
}

Element* Element::getPointer()
{
    return this->pointer;
}

void Element::setPointer(Element* pointer)
{
    this->pointer = pointer;
}

void Element::setExponent(int exponent)
{
    this->exponent = exponent;
}

int Element::getExponent()
{
    return exponent;
}
