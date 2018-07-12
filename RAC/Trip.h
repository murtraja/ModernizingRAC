#pragma once
#include "Location.h"
class Payment;
class Cab;
class Trip {
	Location m_StartLocation;
	Location m_DropLocation;
	Cab *m_pCab{};
	Payment *m_pPayment{};
public:
	Trip();
	~Trip();
	void SetPayment(Payment *p) {
		m_pPayment = p;
	}
	Payment * GetPayment()const {
		return m_pPayment;
	}
	void SetStartLocation(const Location &loc) {
		m_StartLocation = loc;
	}
	void SetDropLocation(const Location &loc) {
		m_DropLocation = loc;
	}
	const Location & GetStartLocation()const {
		return m_StartLocation;
	}
	const Location & GetDropLocation()const {
		return m_DropLocation;
	}
	int GetDistance()const;
	float GetFare()const;
	const std::string GetPaymentType()const;
	const std::string GetCabType()const;
	void SetCab(Cab *p) {
		m_pCab = p;
	}
};

