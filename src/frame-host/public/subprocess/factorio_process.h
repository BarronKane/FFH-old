#pragma once

#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/process.hpp>

namespace factorio
{

class factorio_process
{

public:

	factorio_process();

	

	int spawn(boost::filesystem::path p, std::string args);

private: 

	// TODO: Error check for *nix/win paths.
	boost::filesystem::path path;

	std::vector<std::string> args;

};

} // namespace factorio
