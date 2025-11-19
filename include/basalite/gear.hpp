/**
 * @file gear.hpp
 * @details Gear related definitions
 */

#pragma once

#include <string>
#include <unordered_set>

namespace basalite {

class gear {
private:
	/** @brief Gears required to run this gear. */
	std::unordered_set<std::string> dependencies;

public:
	/** @brief The gear name. */
	std::string name;

	/**
	 * @brief Creates a gear with the given name.
	 * 
	 * @param name the gear name.
	 */
	gear(std::string name);

	/**
	 * @brief Adds a gear dependency.
	 * 
	 * @param name the gear name to add as an dependency.
	 */
	gear* needs(std::string name);

};

}

