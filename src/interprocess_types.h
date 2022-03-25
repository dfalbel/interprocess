#include <boost/interprocess/managed_shared_memory.hpp>
using namespace boost::interprocess;

class Segment {
public:
  managed_shared_memory segment;
  std::string name;
  Segment (std::string name);
  ~Segment ();
};
