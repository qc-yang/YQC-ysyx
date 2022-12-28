// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlab02_light.h for the primary calling header

#include "Vlab02_light___024root.h"
#include "Vlab02_light__Syms.h"

//==========

extern const VlUnpacked<CData/*0:0*/, 512> Vlab02_light__ConstPool__TABLE_641a4ca3_0;
extern const VlUnpacked<CData/*2:0*/, 512> Vlab02_light__ConstPool__TABLE_9165abf2_0;
extern const VlUnpacked<CData/*2:0*/, 512> Vlab02_light__ConstPool__TABLE_0643965b_0;
extern const VlUnpacked<IData/*31:0*/, 512> Vlab02_light__ConstPool__TABLE_c2da2987_0;
extern const VlUnpacked<CData/*7:0*/, 8> Vlab02_light__ConstPool__TABLE_c5bd01dd_0;

VL_INLINE_OPT void Vlab02_light___024root___combo__TOP__1(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___combo__TOP__1\n"); );
    // Variables
    CData/*2:0*/ __Vtableidx2;
    SData/*8:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->rel) << 8U) | (IData)(vlSelf->in));
    vlSelf->d = Vlab02_light__ConstPool__TABLE_641a4ca3_0
        [__Vtableidx1];
    vlSelf->out = Vlab02_light__ConstPool__TABLE_9165abf2_0
        [__Vtableidx1];
    if ((4U & Vlab02_light__ConstPool__TABLE_0643965b_0
         [__Vtableidx1])) {
        vlSelf->lab02_light__DOT__i = Vlab02_light__ConstPool__TABLE_c2da2987_0
            [__Vtableidx1];
    }
    __Vtableidx2 = vlSelf->out;
    vlSelf->seg = Vlab02_light__ConstPool__TABLE_c5bd01dd_0
        [__Vtableidx2];
}

void Vlab02_light___024root___eval(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___eval\n"); );
    // Body
    Vlab02_light___024root___combo__TOP__1(vlSelf);
}

QData Vlab02_light___024root___change_request_1(Vlab02_light___024root* vlSelf);

VL_INLINE_OPT QData Vlab02_light___024root___change_request(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___change_request\n"); );
    // Body
    return (Vlab02_light___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vlab02_light___024root___change_request_1(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vlab02_light___024root___eval_debug_assertions(Vlab02_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab02_light___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rel & 0xfeU))) {
        Verilated::overWidthError("rel");}
}
#endif  // VL_DEBUG
