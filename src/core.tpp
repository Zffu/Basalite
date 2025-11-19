#include <basalite/core.hpp>

using namespace basalite;

gear* basalite_core::get_gear(std::string name) {
	if(this->gears.contains(name)) return this->gears[name];
	return nullptr;
}