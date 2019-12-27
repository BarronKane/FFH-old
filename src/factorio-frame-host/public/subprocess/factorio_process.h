#pragma once

#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/process.hpp>

namespace subprocess
{

class child_process
{

public:

	int spawn(boost::filesystem::path p, std::string args);

private: 

	// TODO: Error check for *nix/win paths.
	boost::filesystem::path path;

};

} // namespace subprocess
