#include "Cash.h"



Cash::Cash() {
}


Cash::~Cash() {
}

void Cash::Pay(float amount) {
	//Mark payment done when driver acknowledges
}

const std::string Cash::GetType() const {
	return "Cash";
}
