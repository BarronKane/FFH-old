#include "subprocess/factorio_process.h"

namespace factorio
{

factorio_process::factorio_process()
{
}

void factorio_process::launch(boost::filesystem::path p, std::string args)
{

    _factorio_process = bp::child(p, args, bp::std_out > _pipe_stream);

    _pipe_stream_reader = std::thread([&]()
		{
			std::string line;
			while (getline(_pipe_stream, line))
			{
				// TODO: This should be piped to log/cout.
				// TODO: Possible deadlock if read is attempted after process exit.
			}
		});

}

factorio_process::~factorio_process()
{
	if (_pipe_stream_reader.joinable())
	{
		_pipe_stream_reader.join();
	}
	if (_factorio_process.running())
	{
		// TODO: Force shutdown/safety.
		_factorio_process.wait();
	}
}

} // namespace factorio
