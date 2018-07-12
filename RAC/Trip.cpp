#include "Trip.h"
#include "Cab.h"
#include "Payment.h"

Trip::Trip() {
}


Trip::~Trip() {
}

int Trip::GetDistance() const {
	return Location::GetDistance(m_StartLocation, m_DropLocation);
}

float Trip::GetFare() const {
	return m_pCab->GetFareUnit() * GetDistance();
}

const std::string Trip::GetPaymentType() const {
	return m_pPayment->GetType() ;
}

const std::string Trip::GetCabType() const {
	return m_pCab->GetType();
}
