#ifndef CALLBACK_H_
#define CALLBACK_H_

#include <iostream>

class Callback {
public :
    virtual ~Callback() {}
	virtual void Execute(void* param) const = 0;
	virtual void* getCInst() const = 0;
};

template <class Clazz>
class TCallback : public Callback {

public:
	typedef void (Clazz::*tFunction)(void* param);

	TCallback(Clazz *pInstance, tFunction pFunc) {
		cInst = pInstance;
		pFunction = pFunc;
	}

	TCallback(const TCallback& instance) {
		this->cInst = instance.cInst;
		this->pFunction = instance.pFunction;
	}

	TCallback& operator=(const TCallback& instance) {
		this->cInst = instance.cInst;
		this->pFunction = instance.pFunction;
		return *this;
	}

	virtual ~TCallback() {
        cInst = NULL;
        pFunction = NULL;
    }

	virtual void Execute(void* param) const {
		if(pFunction) (cInst->*pFunction)(param);
	}

	virtual void* getCInst() const{
		return cInst;
	}

private:
	Clazz *cInst;
	tFunction pFunction;
};


#endif /* CALLBACK_H_ */




