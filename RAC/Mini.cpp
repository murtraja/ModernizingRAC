#include "Mini.h"



Mini::Mini(const std::string &driver, float unit) :Cab{ driver, unit } {
}


Mini::~Mini() {
}

float Mini::GetFareUnit() const {
	return m_FareUnit;
}

const std::string Mini::GetType() const {
	return "Mini";
}
