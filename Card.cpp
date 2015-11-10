#include<iostream>
#include"Card.h"

void Card::show(){
	std::cout<<"[ "<<id<<" : "<<num<<" ]------";
}

/*void Card::change(){
	num = _A;
}*/

ICard& ICard::operator=(const ICard& _icard){
	++_icard.iptr->usecount;
	destroyptr();
	iptr = _icard.iptr;
	return *this;
}

bool ICard::operator == (const ICard& _icard){
	if(iptr->ptr->num == _icard.iptr->ptr->num
		 || iptr->ptr->color == _icard.iptr->ptr->color
		 || iptr->ptr->name ==_icard.iptr->ptr->name)
		return true;
	return false;
}
