// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlab00_light.h for the primary calling header

#ifndef VERILATED_VLAB00_LIGHT___024ROOT_H_
#define VERILATED_VLAB00_LIGHT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vlab00_light__Syms;
class Vlab00_light_VerilatedVcd;


//----------

VL_MODULE(Vlab00_light___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT16(led,15,0);

    // LOCAL SIGNALS
    IData/*31:0*/ lab00_light__DOT__count;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vlab00_light__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vlab00_light___024root);  ///< Copying not allowed
  public:
    Vlab00_light___024root(const char* name);
    ~Vlab00_light___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vlab00_light__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
