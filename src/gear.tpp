#include <basalite/gear.hpp>

using namespace basalite;

gear::gear(std::string name) {
	this->name = name;
}

gear* gear::needs(std::string name) {
	this->dependencies.insert(name);
	return this;
}