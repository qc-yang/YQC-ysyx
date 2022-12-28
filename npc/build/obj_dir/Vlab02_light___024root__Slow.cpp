// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlab02_light.h for the primary calling header

#include "Vlab02_light___024root.h"
#include "Vlab02_light__Syms.h"

//==========


void Vlab02_light___024root___ctor_var_reset(Vlab02_light___024root* vlSelf);

Vlab02_light___024root::Vlab02_light___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vlab02_light___024root___ctor_var_reset(this);
}

void Vlab02_light___024root::__Vconfigure(Vlab02_light__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vlab02_light___024root::~Vlab02_light___024root() {
}

void Vlab02_light___024root___eval_initial(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___eval_initial\n"); );
}

void Vlab02_light___024root___combo__TOP__1(Vlab02_light___024root* vlSelf);

void Vlab02_light___024root___eval_settle(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___eval_settle\n"); );
    // Body
    Vlab02_light___024root___combo__TOP__1(vlSelf);
}

void Vlab02_light___024root___final(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___final\n"); );
}

void Vlab02_light___024root___ctor_var_reset(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->in = 0;
    vlSelf->rel = 0;
    vlSelf->out = 0;
    vlSelf->d = 0;
    vlSelf->seg = 0;
    vlSelf->lab02_light__DOT__i = 0;
}
