// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlab02_light.h for the primary calling header

#ifndef VERILATED_VLAB02_LIGHT___024ROOT_H_
#define VERILATED_VLAB02_LIGHT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vlab02_light__Syms;
class Vlab02_light_VerilatedVcd;


//----------

VL_MODULE(Vlab02_light___024root) {
  public:

    // PORTS
    VL_IN8(in,7,0);
    VL_IN8(rel,0,0);
    VL_OUT8(out,2,0);
    VL_OUT8(d,0,0);
    VL_OUT8(seg,7,0);

    // LOCAL SIGNALS
    IData/*31:0*/ lab02_light__DOT__i;

    // INTERNAL VARIABLES
    Vlab02_light__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vlab02_light___024root);  ///< Copying not allowed
  public:
    Vlab02_light___024root(const char* name);
    ~Vlab02_light___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vlab02_light__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
