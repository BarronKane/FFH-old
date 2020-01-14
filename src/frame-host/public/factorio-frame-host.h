#pragma once

#include <string>
#include <vector>
#include <utility>

#include "factorio_process.h"

namespace factorio
{

/*
template<typename T>
struct argument
{
	std::string ID;
	std::string arg_;
	T value;

	argument(std::string arg, T val)
	{
		arg_ = arg;
		value = val;
	}
	argument(std::string name, std::string arg, T val)
	{
		ID == name;
		arg_ = arg;
		value = val;
	}

};
*/
/*
struct factorio_args
{

	template<typename T>
	void AddArg(const typename argument<T>&)
	{
		arguments.push_back(std::make_tuple(
			argument.name,
			argument.arg_,
			std::to_string(argument.value)
		));
	}

	//std::vector<std::pair<std::string, std::string>> arguments;
	std::vector <std::tuple<std::string, 
							std::string, 
							std::string>> arguments;
};
*/

struct factorio_args_old
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

};

class server : private factorio_process
{

public:

	server();

	/**
	* TODOs: 
	* 1. Args
	* 2. Config propogation.
	* 3. Safe Init/destruction interface.
	* 4. Stdin/stdout monitoring.
	* 5. Stdout log recording.
	*/

	void launch();

	void add_arg(std::string name, std::string arg, std::string value);

private:

	std::vector <std::tuple<std::string,
							std::string,
							std::string>> _arguments;
};


} // namespace factorio
