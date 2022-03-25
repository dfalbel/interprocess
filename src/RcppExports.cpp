// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "interprocess_types.h"
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// create_segment
Rcpp::XPtr<Segment> create_segment(std::string name);
RcppExport SEXP _interprocess_create_segment(SEXP nameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    rcpp_result_gen = Rcpp::wrap(create_segment(name));
    return rcpp_result_gen;
END_RCPP
}
// write_array
void write_array(std::string name, std::string object_name, std::vector<double> values);
RcppExport SEXP _interprocess_write_array(SEXP nameSEXP, SEXP object_nameSEXP, SEXP valuesSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< std::string >::type object_name(object_nameSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type values(valuesSEXP);
    write_array(name, object_name, values);
    return R_NilValue;
END_RCPP
}
// read_array
std::vector<double> read_array(std::string name, std::string object_name);
RcppExport SEXP _interprocess_read_array(SEXP nameSEXP, SEXP object_nameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< std::string >::type object_name(object_nameSEXP);
    rcpp_result_gen = Rcpp::wrap(read_array(name, object_name));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_interprocess_create_segment", (DL_FUNC) &_interprocess_create_segment, 1},
    {"_interprocess_write_array", (DL_FUNC) &_interprocess_write_array, 3},
    {"_interprocess_read_array", (DL_FUNC) &_interprocess_read_array, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_interprocess(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}