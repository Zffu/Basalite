/**
 * @file core.hpp
 * @brief Core basalite system definitions.
 */

#pragma once

#include <unordered_map>

#include <basalite/gear.hpp>

namespace basalite {

class basalite_core {
private:
	/** @brief The registered gears. */
	std::unordered_map<std::string, gear*> gears;

public:
	static basalite_core* instance;

	gear* get_gear(std::string name);

};

}