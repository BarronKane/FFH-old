#include "subprocess/subprocess.h"

namespace subprocess
{

int child_process::spawn(boost::filesystem::path p, std::string args)
{

	boost::process::child c(p, args);

	// Temporary.
	c.wait();
	int result = c.exit_code();
	return result;

}

} // namespace subprocess
