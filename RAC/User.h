#pragma once
#include <string>
#include <vector>
class Payment;
class Trip;
class User {
	std::string m_Name;
	std::string m_Email;
	std::vector<Trip*> m_Trips;
	Trip * m_pCurrentTrip{};
	Payment *m_pPayment{};
public:
	User(const std::string &name, const std::string &email);
	~User();
	void SetCurrentTrip(Trip *trip) {
		m_pCurrentTrip = trip;
	}
	const std::string & GetEmailId()const {
		return m_Email;
	}
	void CompleteTrip();
	void SetPayment(Payment *p) {
		m_pPayment = p;
	}
	Payment * GetPayment()const {
		return m_pPayment;
	}
	std::vector<Trip*>::const_iterator cbegin() {
		return m_Trips.cbegin();
	}
	std::vector<Trip*>::const_iterator cend() {
		return m_Trips.cend();
	}

};

