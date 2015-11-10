#ifndef CARD_H
#define CARD_H

#include<stdlib.h>
#include<time.h>
#include<vector>
#include"Template.h"
#include"Default.h"


//牌类
class Card{

	public:
	short id;
	Card_num num;
	Card_color color;
	Card_name name;
	Card_kind kind;
	short distance;

	public:
	Card(short _id,
			Card_num _num,
			Card_color _color,
			Card_name _name,
			Card_kind _kind,
			short _distance) :	id(_id),
													num(_num),
													color(_color),
													name(_name),
													kind(_kind),
													distance(_distance){ }

	void show();
	//void change();
};

//Card的智能指针类
class ICard{

	private:
	void destroyptr(){ if( --iptr->usecount == 0 ) delete iptr; }

	public:
	IPtr<Card,ICard>* iptr;

	ICard(Card* _ptr_card):iptr(new IPtr<Card,ICard>(_ptr_card)){ }
	ICard(const ICard& _icard):iptr(_icard.iptr){ ++iptr->usecount; }
	~ICard(){ destroyptr(); }

	ICard& operator=(const ICard&);
	bool operator==(const ICard&);
	Card& operator*(){
		return *(iptr->ptr);
	}
	Card* operator->(){
		return iptr->ptr;
	}
	//void show();
};

#endif
