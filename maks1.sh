#! /bin/bash
make
asm(){
local dasm=./resources/asm
local oasm=./asm
if [ $# -eq 2 ]
then
	$dasm $2.s
	hexdump -vC $2.cor > /tmp/asm_demo
	$oasm $2.s
	hexdump -vC $2.cor > /tmp/asm_our
	diff asm_demo asm_our > /tmp/asm_diff
	cat /tmp/asm_diff
fi
}
corewar(){
local dcw=./resources/corewar
local ocw=./corewar
if [ $# -gt 4 ]
then
chs="$chs $5.cor"
fi
if [ $# -gt 3 ]
then
chs="$chs $4.cor"
fi
if [ $# -gt 2 ]
then
chs="$chs $3.cor"
fi
chs="$chs $2.cor"
if [ $# -gt 0 ]
then
	printf "TEST WITH $chs champions\n"
	$dcw $chs > /tmp/cw_demo
	$ocw $chs > /tmp/cw_our
	diff cw_demo cw_our > /tmp/cw_diff
	cat /tmp/cw_diff
	printf "================\n"
fi
}
if [ $# -gt 1 ]
then
	if [ $1 == "cw" ]
	then
		corewar $@
	elif [ $1 == "asm" ]
	then
		asm $@
	fi
fi
