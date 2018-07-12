#include "Location.h"
#include <iostream>
//Using dummy locations
std::pair<std::string, int> startlocations[] = {
	std::make_pair("Pune Airport", 10),
	std::make_pair("Kothrud", 50),
	std::make_pair("Seasons Mall", 20),
	std::make_pair("Central Mall", 120),
	std::make_pair("IT Park", 75),
};
std::pair<std::string, int> droplocations[] = {
	std::make_pair("Railway station", 80),
	std::make_pair("Deccan", 30),
	std::make_pair("DMart", 65),
	std::make_pair("Camp", 110),
	std::make_pair("Ring road", 40),
};
//Geolocation automatically get the location through GPS
void Location::Geolocate() {
	m_Location = startlocations[rand() % 5];
}
//Geocoding gets the location through address
void Location::Geocode(const std::string & address) {
	m_Location = droplocations[rand() % 5];
}

int Location::GetDistance(const Location & start, const Location & end) {
	return std::abs(start.GetLatLng() - end.GetLatLng());
}
