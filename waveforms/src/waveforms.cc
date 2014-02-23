/**
 * @file  waveforms.cc
 * @brief commonly used signal waveform generators 
 *
**/

#include <constants.hh>
#include <waveforms.hh>
using namespace comsigproc;

template <typename T>
constexpr T sinc(const T& x)
{
    return (x == 0) ? 1 : sin(PI * x) / (PI * x);
}


