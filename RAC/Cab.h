#pragma once
#include <string>
#include "Location.h"
class Cab {
	std::string m_Driver;
	Location m_Location;
protected:
	float m_FareUnit{};
public:
	Cab(const std::string &driver, float unit) :m_Driver{ driver }, m_FareUnit{ unit } {

	}
	virtual ~Cab() {}
	virtual float GetFareUnit()const = 0;
	const Location & GetLocation()const {
		return m_Location;
	}
	virtual const std::string GetType()const = 0;
};

