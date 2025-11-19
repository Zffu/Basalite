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
		std::cout << ERR_PREFIX << "The basalite core isn't loaded yet! You cannot run anything!";
		return;
	}


	for(std::string dep : this->dependencies) {
		if(basalite_core::instance->already_ran(dep)) continue;

		gear* gear = basalite_core::instance->get_gear(dep);

		if(gear == nullptr) {
			std::cout << ERR_PREFIX << "Task " << dep << " was added as an dependency but wasn't found within the basalite core! Impossible resolution";
			continue;
		}

		gear->run();
	}

	std::cout << PREFIX << "Running task " << this->name;
}