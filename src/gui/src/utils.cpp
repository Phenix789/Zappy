#include <boost/thread/thread.hpp>
#include "utils.hpp"

namespace utils
{
  void	sleep(int millisec)
  {
    boost::this_thread::sleep(boost::posix_time::milliseconds(millisec));
  }
};
