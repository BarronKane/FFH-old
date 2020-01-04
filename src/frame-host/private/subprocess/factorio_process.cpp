#include "subprocess/factorio_process.h"

namespace factorio
{

factorio_process::factorio_process()
{

}

void factorio_process::launch(boost::filesystem::path p, std::string args)
{

	factorio_subprocess = bp::child(p, args, bp::std_out > pipe_stream);

	pipe_stream_reader = std::thread([&]()
		{
			std::string line;
			while (getline(pipe_stream, line))
			{
				// TODO: This should be piped to log/cout.
				// TODO: Possible deadlock if read is attempted after process exit.
			}
		});

}

factorio_process::~factorio_process()
{
	if (pipe_stream_reader.joinable())
	{
		pipe_stream_reader.join();
	}
	if (factorio_subprocess.running())
	{
		// TODO: Force shutdown/safety.
		factorio_subprocess.wait();
	}
}

} // namespace factorio
