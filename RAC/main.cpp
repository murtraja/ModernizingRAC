#include <iostream>
#include <ctime>
#include "User.h"
#include "BookingManager.h"
#include "Trip.h"
#include "Location.h"
#include "Cash.h"
#include "Mini.h"
BookingManager mgr;
void Register() {
	mgr.Register(new User{ "Umar", "umar.lone@poash.com" });
	mgr.Register(new User{ "Ayaan", "ayaan@gmail.com" });
	mgr.Register(new User{ "Raihaan", "raihaan@poash.com" });
	mgr.Register(new User{ "Sam", "sam@poash.com" });
	mgr.Register(new User{ "Sam", "sam@poash.com" });
}
void Book(const std::string &email) {
	mgr.BookCab(email);

	Trip *p = new Trip{};
	Location start;
	start.Geolocate();
	Location end;
	//Will automatically choose address during testing
	end.Geocode("Dummy");
	p->SetStartLocation(start);
	p->SetDropLocation(end);
	p->SetPayment(new Cash{});
	p->SetCab(new Mini{ "Bob", 10 });

	std::cout << "\n>>> Trip Details <<<" << std::endl;
	std::cout << "Pickup : " << p->GetStartLocation().GetAddress() << std::endl;
	std::cout << "Drop : " << p->GetDropLocation().GetAddress() << std::endl;
	std::cout << "Distance :" << p->GetDistance() << " kms"<< std::endl;
	std::cout << "Fare : " << p->GetFare() << " Rs" << std::endl; 
	std::cout << "Payment : " << p->GetPaymentType() << std::endl;

	mgr.Start(p);
	mgr.End();
}
void ShowDetails(const std::string &email) {
	User *p = mgr.GetUser(email);
	if (p == nullptr) {
		std::cout << "No such user" << std::endl; 
		return;
	}
	std::vector<Trip*>::const_iterator cb = p->cbegin();
	std::cout << "\n\n All trip" << std::endl;
	while (cb != p->cend()) {
		const Trip *p = *cb++;
		std::cout << "\n>>> Trip Details <<<" << std::endl;
		std::cout << "Pickup : " << p->GetStartLocation().GetAddress() << std::endl;
		std::cout << "Drop : " << p->GetDropLocation().GetAddress() << std::endl;
		std::cout << "Distance :" << p->GetDistance() << " kms" << std::endl;
		std::cout << "Fare : " << p->GetFare() << " Rs" << std::endl;
		std::cout << "Payment : " << p->GetPaymentType() << std::endl;
	}
}
int main() {
	srand(time(NULL));
	//for (int i = 0; i < 5; ++i) {
	//	std::cout << rand() % 5 << std::endl; 
	//}
	std::cout << "User module" << std::endl;
	Register();
	Book("ayaan@gmail.com");
	Book("ayaan@gmail.com");
	Book("ayaan@gmail.com");
	ShowDetails("ayaan@gmail.com");
}