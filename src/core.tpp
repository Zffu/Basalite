#include <basalite/core.hpp>

using namespace basalite;

gear* basalite_core::get_gear(std::string name) {
	if(this->gears.contains(name)) return this->gears[name];
	return nullptr;
}

void basalite_core::register_gear(gear* gear) {
	if(this->gears.contains(gear->name)) return;

	this->gears[gear->name] = gear;
}

basalite_core* basalite_core::instance = nullptr;