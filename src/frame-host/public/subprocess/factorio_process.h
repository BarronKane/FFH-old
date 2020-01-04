#pragma once

#include <string>
#include <vector>
#include <thread>

#include <boost/noncopyable.hpp>
#include <boost/filesystem.hpp>
#include <boost/process.hpp>

namespace bp = boost::process;

namespace factorio
{

// TODO: This may end up a singleton or otherwise noncopyable.
class factorio_process : private boost::noncopyable
{

public:

	factorio_process();
	~factorio_process();

	

	void launch(boost::filesystem::path p, std::string args);

private: 

	// TODO: Error check for *nix/win paths.
	boost::filesystem::path path_;
	std::vector<std::string> args_;
	
	bp::child factorio_subprocess;
	bp::ipstream pipe_stream;

	std::thread pipe_stream_reader;
};

} // namespace factorio
