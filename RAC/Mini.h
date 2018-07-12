#pragma once
#include "Cab.h"
class Mini :
	public Cab {
public:
	Mini(const std::string &driver, float unit);
	~Mini();
	float GetFareUnit()const;
	virtual const std::string GetType()const;
};

