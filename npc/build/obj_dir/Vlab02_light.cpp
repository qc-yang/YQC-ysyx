// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlab02_light.h"
#include "Vlab02_light__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vlab02_light::Vlab02_light(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vlab02_light__Syms(_vcontextp__, _vcname__, this)}
    , in{vlSymsp->TOP.in}
    , rel{vlSymsp->TOP.rel}
    , out{vlSymsp->TOP.out}
    , d{vlSymsp->TOP.d}
    , seg{vlSymsp->TOP.seg}
    , rootp{&(vlSymsp->TOP)}
{
}

Vlab02_light::Vlab02_light(const char* _vcname__)
    : Vlab02_light(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vlab02_light::~Vlab02_light() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vlab02_light___024root___eval_initial(Vlab02_light___024root* vlSelf);
void Vlab02_light___024root___eval_settle(Vlab02_light___024root* vlSelf);
void Vlab02_light___024root___eval(Vlab02_light___024root* vlSelf);
QData Vlab02_light___024root___change_request(Vlab02_light___024root* vlSelf);
#ifdef VL_DEBUG
void Vlab02_light___024root___eval_debug_assertions(Vlab02_light___024root* vlSelf);
#endif  // VL_DEBUG
void Vlab02_light___024root___final(Vlab02_light___024root* vlSelf);

static void _eval_initial_loop(Vlab02_light__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vlab02_light___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vlab02_light___024root___eval_settle(&(vlSymsp->TOP));
        Vlab02_light___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vlab02_light___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/yqc/ysyx-workbench/npc/vsrc/lab02_light.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vlab02_light___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vlab02_light::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlab02_light::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vlab02_light___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vlab02_light___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vlab02_light___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/yqc/ysyx-workbench/npc/vsrc/lab02_light.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vlab02_light___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vlab02_light::final() {
    Vlab02_light___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vlab02_light::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vlab02_light::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vlab02_light___024root__traceInitTop(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vlab02_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlab02_light___024root*>(voidSelf);
    Vlab02_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vlab02_light___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vlab02_light___024root__traceRegister(Vlab02_light___024root* vlSelf, VerilatedVcd* tracep);

void Vlab02_light::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vlab02_light___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
