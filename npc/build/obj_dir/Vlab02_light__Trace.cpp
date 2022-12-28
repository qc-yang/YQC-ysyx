// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlab02_light__Syms.h"


void Vlab02_light___024root__traceChgSub0(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep);

void Vlab02_light___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vlab02_light___024root* const __restrict vlSelf = static_cast<Vlab02_light___024root*>(voidSelf);
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vlab02_light___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vlab02_light___024root__traceChgSub0(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlSelf->in),8);
        tracep->chgBit(oldp+1,(vlSelf->rel));
        tracep->chgCData(oldp+2,(vlSelf->out),3);
        tracep->chgBit(oldp+3,(vlSelf->d));
        tracep->chgCData(oldp+4,(vlSelf->seg),8);
        tracep->chgIData(oldp+5,(vlSelf->lab02_light__DOT__i),32);
    }
}

void Vlab02_light___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vlab02_light___024root* const __restrict vlSelf = static_cast<Vlab02_light___024root*>(voidSelf);
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
