#include "BookingManager.h"
#include <iostream>
#include <algorithm>
#include "User.h"
#include "Trip.h"


struct MatchUser {
	std::string m_Email;
	MatchUser(const std::string &email) :m_Email{ email } {

	}
	bool operator()(User *user)const {
		return m_Email == user->GetEmailId();
	}
};
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
	std::vector<User*>::iterator it = find_if(m_Users.begin(), m_Users.end(), MatchUser{ email });
	if (it == m_Users.end()) {
		std::cout << "You need to register before you can book a cab" << std::endl;
		return;
	}
	m_pCurrentUser = *it;
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
	std::vector<User*>::iterator it= find_if(m_Users.begin(), m_Users.end(), MatchUser{ email });
	return it != m_Users.end();
}

User * BookingManager::GetUser(const std::string & email) {
	std::vector<User*>::iterator it = find_if(m_Users.begin(), m_Users.end(), MatchUser{ email });
	return (it != m_Users.end() ? *it : nullptr);
}
