#pragma once

#include <string>

#include "factorio_process.h"

namespace factorio
{

class server
{

public:

	server();

	void build_args();

	/**
	* TODOs: 
	* 1. Args
	* 2. Config propogation.
	* 3. Safe Init/destruction interface.
	* 4. Stdin/stdout monitoring.
	* 5. Stdout log recording.
	*/


private:

	factorio_process process;
};


} // namespace factorio
