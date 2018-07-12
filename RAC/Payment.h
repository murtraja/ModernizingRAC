#pragma once
#include <string>
class Payment {
public:
	virtual ~Payment() {}
	virtual void Pay(float amount) = 0;
	virtual const std::string GetType()const = 0;
};

