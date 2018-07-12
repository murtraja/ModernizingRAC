#pragma once
#include <vector>
class Trip;
class User;
class BookingManager {
	std::vector<User*> m_Users;
	User *m_pCurrentUser;
public:
	BookingManager();
	~BookingManager();
	void Register(User *pUser);
	void BookCab(const std::string &email);
	void Start(Trip *p);
	void End();
	bool IsRegistered(const std::string &email);
	User * GetUser(const std::string &email);
};

