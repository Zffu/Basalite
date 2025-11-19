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

	/** @brief The gears that already ran. */
	std::unordered_set<std::string> ran_gears;

public:
	/** @brief The current basalite core. */
	static basalite_core* instance;

	/** 
	 * @brief Gets the gear.
	 * 
	 * @param the gear name to get.
	 * 
	 * @return the gear.
	 * @retval nullptr the gear was not found.
	 */
	gear* get_gear(std::string name);

	/**
	 * @brief Registers a gear.
	 * 
	 * @param gear the gear to return.
	 */
	void register_gear(gear* gear);

	bool already_ran(std::string gear);

	void run_gear(gear* gear);
};

}