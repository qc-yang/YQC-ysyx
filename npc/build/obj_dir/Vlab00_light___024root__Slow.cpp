// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlab00_light.h for the primary calling header

#include "Vlab00_light___024root.h"
#include "Vlab00_light__Syms.h"

//==========


void Vlab00_light___024root___ctor_var_reset(Vlab00_light___024root* vlSelf);

Vlab00_light___024root::Vlab00_light___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vlab00_light___024root___ctor_var_reset(this);
}

void Vlab00_light___024root::__Vconfigure(Vlab00_light__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vlab00_light___024root::~Vlab00_light___024root() {
}

void Vlab00_light___024root___eval_initial(Vlab00_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab00_light___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vlab00_light___024root___eval_settle(Vlab00_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab00_light___024root___eval_settle\n"); );
}

void Vlab00_light___024root___final(Vlab00_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab00_light___024root___final\n"); );
}

void Vlab00_light___024root___ctor_var_reset(Vlab00_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab00_light___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->led = 0;
    vlSelf->lab00_light__DOT__count = 0;
}
