#include "User.h"

#include "Trip.h"
#include "Payment.h"

User::User(const std::string & name, const std::string & email) :m_Name{ name }, m_Email{ email } {
}

User::~User() {
}

void User::CompleteTrip() {
	m_pPayment->Pay(m_pCurrentTrip->GetFare());
	m_Trips.push_back(m_pCurrentTrip);
	m_pCurrentTrip = nullptr;
}
