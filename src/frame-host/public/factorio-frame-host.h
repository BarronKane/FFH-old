#pragma once

#include <string>
#include <vector>
#include <utility>

#include "factorio_process.h"

namespace factorio
{

struct factorio_args
{
	std::vector<std::pair<std::string, std::string>> args_;
};

class server : private factorio_process
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

	void init();

	factorio_args args_;
};


} // namespace factorio
