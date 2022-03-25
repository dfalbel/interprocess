// [[Rcpp::depends(BH)]]
#include <Rcpp.h>
#include "interprocess_types.h"
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
using namespace Rcpp;

Segment::Segment (std::string name) {
  shared_memory_object::remove(name.c_str());
  segment = managed_shared_memory(create_only, name.c_str(), 65536);
  this->name = name;
}

Segment::~Segment () {
  Rcpp::Rcout << "Deleting segment '" << name << "'" << std::endl;
  shared_memory_object::remove(name.c_str());
}

// [[Rcpp::export]]
Rcpp::XPtr<Segment> create_segment (std::string name) {
  return Rcpp::XPtr<Segment>(new Segment(name));
}

typedef allocator<double, managed_shared_memory::segment_manager>
  ShmemAllocator;

typedef vector<double, ShmemAllocator>
  shared_double_vector;

// [[Rcpp::export]]
void write_array (std::string name, std::string object_name, std::vector<double> values) {

  managed_shared_memory segment(open_only, name.c_str());

  //Initialize shared memory STL-compatible allocator
  const ShmemAllocator alloc_inst (segment.get_segment_manager());

  // Allocate vector in the shared memory
  shared_double_vector* vec= segment.construct<shared_double_vector>
    (object_name.c_str()) //object name
    (alloc_inst);//first ctor parameter

  for (auto el : values) {
    vec->push_back(el);
  }
}

// [[Rcpp::export]]
std::vector<double> read_array (std::string name, std::string object_name) {
  managed_shared_memory segment(open_only, name.c_str());
  auto res = segment.find<shared_double_vector> (object_name.c_str()).first;
  auto value = std::vector<double>(res->begin(), res->end());
  segment.destroy<shared_double_vector>(object_name.c_str());
  return value;
}


