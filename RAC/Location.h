#pragma once
#include <string>
#include <utility>
class Location {
	std::pair<std::string, int> m_Location;
public:
	void Geolocate();
	void Geocode(const std::string &address);
	int GetLatLng()const {
		return m_Location.second;
	}
	const std::string & GetAddress()const {
		return m_Location.first;
	}
	static int GetDistance(const Location &start, const Location &end);
};

