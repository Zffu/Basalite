#include <basalite/core.hpp>

#include <basalite/log.hpp>

#include <iostream>

using namespace basalite;

gear* basalite_core::get_gear(std::string name) {
	if(this->gears.contains(name)) return this->gears[name];
	return nullptr;
}

void basalite_core::register_gear(gear* gear) {
	if(this->gears.contains(gear->name)) return;

	this->gears[gear->name] = gear;
}

bool basalite_core::already_ran(std::string name) {
	return this->ran_gears.contains(name);
}

void basalite_core::run_gear(gear* gr) {
	std::cout << INFO_PREFX << "Running gear " << gr->name;

	for(std::string dep : gr->dependencies) {
		if(this->already_ran(dep)) continue;

		gear* g = this->get_gear(dep);

		if(g == nullptr) {
			std::cout << ERR_PREFIX << "Task " << dep << " was added as an dependency but wasn't found within the basalite core! Impossible resolution\n";
			continue;
		}

		g->run();
	}

	std::cout << INFO_PREFX << "Running gear " << gr->name;

	gr->execute();
	
	this->ran_gears.insert(gr->name);
}


basalite_core* basalite_core::instance = nullptr;