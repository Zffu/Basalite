#include <basalite/gear.hpp>
#include <basalite/core.hpp>

#include <basalite/log.hpp>

#include <iostream>

using namespace basalite;

gear::gear(std::string name) {
	this->name = name;
}

gear* gear::needs(std::string name) {
	this->dependencies.insert(name);
	return this;
}

void gear::run() {
	if(basalite_core::instance == nullptr) {
		std::cout << ERR_PREFIX << "The basalite core isn't loaded yet! You cannot run anything!\n";
		return;
	}

	if(this->can_skip()) return;

	basalite_core::instance->run_gear(this);
}