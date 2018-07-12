#include "BookingManager.h"
#include <iostream>
#include <algorithm>
#include "User.h"
#include "Trip.h"

BookingManager::BookingManager() {
}


BookingManager::~BookingManager() {
}

void BookingManager::Register(User * pUser) {
	if (IsRegistered(pUser->GetEmailId())) {
		std::cout << "You're already registered" << std::endl; 
		return;
	}
	m_Users.push_back(pUser);
}

void BookingManager::BookCab(const std::string & email) {
	//Book the cab
	if (IsRegistered(email)) {
		std::cout << "You need to register before you can book a cab" << std::endl;
		return;
	}
	m_pCurrentUser = GetUser(email);
}

void BookingManager::Start(Trip * p) {
	if (m_pCurrentUser->GetPayment() == nullptr) {
		m_pCurrentUser->SetPayment(p->GetPayment());
	} else {
		p->SetPayment(m_pCurrentUser->GetPayment());
	}
	m_pCurrentUser->SetCurrentTrip(p);
}
void BookingManager::End() {
	m_pCurrentUser->CompleteTrip();
	m_pCurrentUser = nullptr;
}
bool BookingManager::IsRegistered(const std::string & email) {
	User* user = GetUser(email);
	if (user) {
		return true;
	}
	return false;
}

User * BookingManager::GetUser(const std::string & email) {
	std::vector<User*>::iterator it = find_if(m_Users.begin(), m_Users.end(),
		[&email](User* user) { return user->GetEmailId() == email; });
	return (it != m_Users.end() ? *it : nullptr);
}
