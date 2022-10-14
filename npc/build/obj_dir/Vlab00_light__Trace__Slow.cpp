// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlab00_light__Syms.h"


void Vlab00_light___024root__traceInitSub0(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vlab00_light___024root__traceInitTop(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vlab00_light___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vlab00_light___024root__traceInitSub0(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"rst", false,-1);
        tracep->declBus(c+3,"led", false,-1, 15,0);
        tracep->declBit(c+1,"lab00_light clk", false,-1);
        tracep->declBit(c+2,"lab00_light rst", false,-1);
        tracep->declBus(c+3,"lab00_light led", false,-1, 15,0);
        tracep->declBus(c+4,"lab00_light count", false,-1, 31,0);
    }
}

void Vlab00_light___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vlab00_light___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vlab00_light___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vlab00_light___024root__traceRegister(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vlab00_light___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vlab00_light___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vlab00_light___024root__traceCleanup, vlSelf);
    }
}

void Vlab00_light___024root__traceFullSub0(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vlab00_light___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vlab00_light___024root* const __restrict vlSelf = static_cast<Vlab00_light___024root*>(voidSelf);
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vlab00_light___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vlab00_light___024root__traceFullSub0(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullBit(oldp+2,(vlSelf->rst));
        tracep->fullSData(oldp+3,(vlSelf->led),16);
        tracep->fullIData(oldp+4,(vlSelf->lab00_light__DOT__count),32);
    }
}
