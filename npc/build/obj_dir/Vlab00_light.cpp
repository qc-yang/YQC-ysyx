// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlab00_light.h"
#include "Vlab00_light__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vlab00_light::Vlab00_light(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vlab00_light__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
}

Vlab00_light::Vlab00_light(const char* _vcname__)
    : Vlab00_light(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vlab00_light::~Vlab00_light() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vlab00_light___024root___eval_initial(Vlab00_light___024root* vlSelf);
void Vlab00_light___024root___eval_settle(Vlab00_light___024root* vlSelf);
void Vlab00_light___024root___eval(Vlab00_light___024root* vlSelf);
QData Vlab00_light___024root___change_request(Vlab00_light___024root* vlSelf);
#ifdef VL_DEBUG
void Vlab00_light___024root___eval_debug_assertions(Vlab00_light___024root* vlSelf);
#endif  // VL_DEBUG
void Vlab00_light___024root___final(Vlab00_light___024root* vlSelf);

static void _eval_initial_loop(Vlab00_light__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vlab00_light___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vlab00_light___024root___eval_settle(&(vlSymsp->TOP));
        Vlab00_light___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vlab00_light___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/yqc/ysyx-workbench/npc/vsrc/lab00_light.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vlab00_light___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vlab00_light::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlab00_light::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vlab00_light___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vlab00_light___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vlab00_light___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/yqc/ysyx-workbench/npc/vsrc/lab00_light.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vlab00_light___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vlab00_light::final() {
    Vlab00_light___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vlab00_light::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vlab00_light::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vlab00_light___024root__traceInitTop(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vlab00_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlab00_light___024root*>(voidSelf);
    Vlab00_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vlab00_light___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vlab00_light___024root__traceRegister(Vlab00_light___024root* vlSelf, VerilatedVcd* tracep);

void Vlab00_light::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vlab00_light___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
