#ifndef TEMPLATE_H
#define TEMPLATE_H

template<class T,class G>
class IPtr {
	friend G;
	private:
	T* ptr;
	size_t usecount;
	IPtr(T* _ptr):ptr(_ptr),usecount(1){}
	~IPtr(){delete ptr;}
};

#endif