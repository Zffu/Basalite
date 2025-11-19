#include <basalite/core.hpp>
#include <basalite/gear.hpp>

using namespace basalite;

int main() {
	basalite_core* core = new basalite_core();
	basalite_core::instance = core;

	gear* dep1 = new gear("dep1");
	gear* dep2 = new gear("dep2");

	core->register_gear(dep1);
	core->register_gear(dep2);

	gear* main = (new gear("main"))->needs("dep1")->needs("dep2");

	core->register_gear(main);

	main->run();
}