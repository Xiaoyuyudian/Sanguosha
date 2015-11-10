#include<iostream>
#include"Role.h"

void Role::show(){
	std::cout<<name<<"    ";
}

/*void Card::change(){
	num = _A;
}*/

IRole& IRole::operator=(const IRole& _irole){
	++_irole.iptr->usecount;
	destroyptr();
	iptr = _irole.iptr;
	return *this;
}