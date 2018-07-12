#pragma once
#include "Payment.h"
class Cash :
	public Payment {
public:
	Cash();
	~Cash();
	virtual void Pay(float amount) ;
	virtual const std::string GetType()const;


};

