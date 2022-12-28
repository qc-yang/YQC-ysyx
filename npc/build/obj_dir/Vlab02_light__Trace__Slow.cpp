// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlab02_light__Syms.h"


void Vlab02_light___024root__traceInitSub0(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vlab02_light___024root__traceInitTop(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vlab02_light___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vlab02_light___024root__traceInitSub0(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"in", false,-1, 7,0);
        tracep->declBit(c+2,"rel", false,-1);
        tracep->declBus(c+3,"out", false,-1, 2,0);
        tracep->declBit(c+4,"d", false,-1);
        tracep->declBus(c+5,"seg", false,-1, 7,0);
        tracep->declBus(c+1,"lab02_light in", false,-1, 7,0);
        tracep->declBit(c+2,"lab02_light rel", false,-1);
        tracep->declBus(c+3,"lab02_light out", false,-1, 2,0);
        tracep->declBit(c+4,"lab02_light d", false,-1);
        tracep->declBus(c+5,"lab02_light seg", false,-1, 7,0);
        tracep->declBus(c+6,"lab02_light i", false,-1, 31,0);
        tracep->declBus(c+3,"lab02_light seg0 in", false,-1, 2,0);
        tracep->declBus(c+5,"lab02_light seg0 out", false,-1, 7,0);
    }
}

void Vlab02_light___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vlab02_light___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vlab02_light___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vlab02_light___024root__traceRegister(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vlab02_light___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vlab02_light___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vlab02_light___024root__traceCleanup, vlSelf);
    }
}

void Vlab02_light___024root__traceFullSub0(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vlab02_light___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vlab02_light___024root* const __restrict vlSelf = static_cast<Vlab02_light___024root*>(voidSelf);
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vlab02_light___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vlab02_light___024root__traceFullSub0(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->in),8);
        tracep->fullBit(oldp+2,(vlSelf->rel));
        tracep->fullCData(oldp+3,(vlSelf->out),3);
        tracep->fullBit(oldp+4,(vlSelf->d));
        tracep->fullCData(oldp+5,(vlSelf->seg),8);
        tracep->fullIData(oldp+6,(vlSelf->lab02_light__DOT__i),32);
    }
}
