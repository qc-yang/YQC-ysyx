// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlab00_light__Syms.h"


void Vlab00_light___024root__traceChgSub0(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep);

void Vlab00_light___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vlab00_light___024root* const __restrict vlSelf = static_cast<Vlab00_light___024root*>(voidSelf);
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vlab00_light___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vlab00_light___024root__traceChgSub0(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->clk));
        tracep->chgBit(oldp+1,(vlSelf->rst));
        tracep->chgSData(oldp+2,(vlSelf->led),16);
        tracep->chgIData(oldp+3,(vlSelf->lab00_light__DOT__count),32);
    }
}

void Vlab00_light___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vlab00_light___024root* const __restrict vlSelf = static_cast<Vlab00_light___024root*>(voidSelf);
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
