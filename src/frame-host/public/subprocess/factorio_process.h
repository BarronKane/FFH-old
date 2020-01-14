#pragma once

#include <string>
#include <thread>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/noncopyable.hpp>
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

	virtual void launch(boost::filesystem::path p, std::string args);

private:

	// TODO: Error check for *nix/win paths.
	boost::filesystem::path _path;
	std::string _args;
	
	bp::child _factorio_process;
	bp::ipstream _pipe_stream;

	std::thread _pipe_stream_reader;
};

} // namespace factorio
