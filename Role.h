#ifndef ROLE_H
#define ROLE_H

#include<stdlib.h>
#include<time.h>
#include<vector>
#include"Template.h"
#include"Default.h"

//角色类
class Role{

	private:
	Role_name name;
	Role_sex sex;
	Role_country country;
	short maxblood;


	public:
	Role(Role_name _name,
			Role_sex _sex,
			Role_country _country,
			int _maxblood) :	name(_name),
												sex(_sex),
												country(_country),
												maxblood(_maxblood){ }

	void show();
	//void change();
};

// Role的智能指针类
class IRole{
	private:
	IPtr<Role,IRole>* iptr;
	void destroyptr(){ if( --iptr->usecount == 0 ) delete iptr; }

	public:
	IRole(Role* _ptr_role):iptr(new IPtr<Role,IRole>(_ptr_role)){ }
	IRole(const IRole& _irole):iptr(_irole.iptr){ ++iptr->usecount; }
	~IRole(){ destroyptr(); }

	IRole& operator=(const IRole&);
	Role& operator*(){
		return *(iptr->ptr);
	}
	Role* operator->(){
		return iptr->ptr;
	}
	//void show();
};

#endif
