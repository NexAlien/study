#!/usr/bin/python
import sys  # not used in BOA
sys.path.append("../lib")  # not used in BOA

g_debug = True
if g_debug:
    from boa_simulate import *

lib_sw = boaimport('BU_FU_switchover_lib')

if g_debug:
    def log(str):
        return lib_sw.log(str)

    def cli(str):
        return lib_sw.cli(str)

    def stop_tc_execution():
        return lib_sw.stop_tc_execution()

    def wait_trigger():
        return lib_sw.wait_trigger()

    def send_trigger():
         return lib_sw.send_trigger()

wait_trigger()
CMRG_switchover = lib_sw.switchoverILRG('MGW_CMRG')
#do first switchover
if not CMRG_switchover.doSwitchover():   
        stop_tc_execution()        
send_trigger()

#do switchover one more time
wait_trigger()
if not CMRG_switchover.doSwitchover():
        stop_tc_execution()
send_trigger()
