#pragma once

#include <string>
#include <vector>
#include <utility>

#include "factorio_process.h"

namespace factorio
{

struct factorio_args
{
	// These are all strings (for now) to allow flexibility.
	// TODO: Checks for acceptible inputs.

	// REQUIRED/OPTIONALLY DEFAULT
	std::string library_path;
	std::string executable_path;

	std::string bind;
	std::string port;
	std::string server_settings;
	std::string rcon_port;
	std::string rcon_password;

	std::string server_adminlist;

	// OPTIONAL
	std::string mod_directory;

	std::vector<std::pair<std::string, std::string>> arguments;
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

	std::unique_ptr<factorio_args> m_args = std::make_unique<factorio_args>();
};


} // namespace factorio
