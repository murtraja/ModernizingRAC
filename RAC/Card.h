#pragma once
#include "Payment.h"
class Card :
	public Payment {
public:
	Card();
	~Card();
	virtual void Pay(float amount);
};

