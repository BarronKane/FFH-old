#include "subprocess/factorio_process.h"

namespace factorio
{

factorio_process::factorio_process()
{

}

int factorio_process::spawn(boost::filesystem::path p, std::string args)
{

	boost::process::child c(p, args);

	// Temporary.
	c.wait();
	int result = c.exit_code();
	return result;

}

} // namespace factorio
