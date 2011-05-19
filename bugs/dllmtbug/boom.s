	.file	"boom.cc"
	.intel_syntax
 # GNU C++ version 3.4.5 (mingw special) (mingw32)
 #	compiled by GNU C version 3.4.5 (mingw special).
 # GGC heuristics: --param ggc-min-expand=99 --param ggc-min-heapsize=130869
 # options passed:  -Ie:/job/ltwood/lwdg/include -iprefix -masm=intel
 # -auxbase-strip -O2 -Wall -fverbose-asm -ffast-math
 # -oe:/job/ltwood/lwdg/trunk/obj/mingw__debugging__boomdll__boom.o
 # options enabled:  -feliminate-unused-debug-types -fdefer-pop
 # -foptimize-sibling-calls -funit-at-a-time -fcse-follow-jumps
 # -fcse-skip-blocks -fexpensive-optimizations -fthread-jumps
 # -fstrength-reduce -fpeephole -fforce-mem -ffunction-cse
 # -fkeep-static-consts -fcaller-saves -freg-struct-return -fgcse -fgcse-lm
 # -fgcse-sm -fgcse-las -floop-optimize -fcrossjumping -fif-conversion
 # -fif-conversion2 -frerun-cse-after-loop -frerun-loop-opt
 # -fdelete-null-pointer-checks -fschedule-insns2 -fsched-interblock
 # -fsched-spec -fsched-stalled-insns -fsched-stalled-insns-dep
 # -fbranch-count-reg -freorder-blocks -freorder-functions
 # -fcprop-registers -fcommon -fverbose-asm -fregmove
 # -foptimize-register-move -fargument-alias -fstrict-aliasing
 # -fmerge-constants -fzero-initialized-in-bss -fident -fpeephole2
 # -ffinite-math-only -fguess-branch-probability
 # -funsafe-math-optimizations -m80387 -mhard-float -mno-soft-float
 # -malign-double -mfp-ret-in-387 -mstack-arg-probe
 # -maccumulate-outgoing-args -mno-red-zone -mtune=pentiumpro -march=i386
 # -masm=intel

	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.text
	.align 2
	.p2align 4,,15
.globl _boom
	.def	_boom;	.scl	2;	.type	32;	.endef
_boom:
L2:
	push	ebp	 #
	mov	ebp, esp	 #,
	lea	eax, [ebp-12]	 #,
	sub	esp, 88	 #,
	mov	DWORD PTR [ebp-32], eax	 #,
	lea	eax, [ebp-64]	 # tmp66,
	mov	DWORD PTR [esp], eax	 #, tmp66
	mov	DWORD PTR [ebp-12], ebx	 #,
	mov	DWORD PTR [ebp-8], esi	 #,
	mov	DWORD PTR [ebp-4], edi	 #,
	mov	DWORD PTR [ebp-40], OFFSET FLAT:___gxx_personality_sj0	 #,
	mov	DWORD PTR [ebp-36], OFFSET FLAT:LLSDA2	 #,
	mov	DWORD PTR [ebp-28], OFFSET FLAT:L9	 #,
	mov	DWORD PTR [ebp-24], esp	 #,
	call	__Unwind_SjLj_Register	 #
	mov	DWORD PTR [esp], 4	 #,
	call	___cxa_allocate_exception	 #
	mov	DWORD PTR [eax], 3	 #* <anonymous>,
	xor	ecx, ecx	 #
	mov	edx, OFFSET FLAT:__ZTIi	 #,
	mov	DWORD PTR [esp+8], ecx	 #,
	mov	DWORD PTR [esp+4], edx	 #,
	mov	DWORD PTR [esp], eax	 #, <anonymous>
	mov	DWORD PTR [ebp-60], 1	 #,
	call	___cxa_throw	 #
	.p2align 4,,7
L9:
L5:
L6:
L1:
	add	ebp, 12	 #,
	mov	eax, DWORD PTR [ebp-56]	 # tmp60,
	mov	DWORD PTR [esp], eax	 #, tmp60
	call	___cxa_begin_catch	 #
	mov	DWORD PTR [ebp-60], 0	 #,
	call	___cxa_end_catch	 #
	lea	eax, [ebp-64]	 # tmp68,
	mov	DWORD PTR [esp], eax	 #, tmp68
	call	__Unwind_SjLj_Unregister	 #
	mov	ebx, DWORD PTR [ebp-12]	 #,
	mov	eax, 1	 # <result>,
	mov	esi, DWORD PTR [ebp-8]	 #,
	mov	edi, DWORD PTR [ebp-4]	 #,
	mov	esp, ebp	 #,
	pop	ebp	 #
	ret
	.section	.gcc_except_table,"dr"
	.align 4
LLSDA2:
	.byte	0xff
	.byte	0x0
	.uleb128 LLSDATT2-LLSDATTD2
LLSDATTD2:
	.byte	0x1
	.uleb128 LLSDACSE2-LLSDACSB2
LLSDACSB2:
	.uleb128 0x0
	.uleb128 0x1
LLSDACSE2:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0
LLSDATT2:
	.text
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_throw;	.scl	2;	.type	32;	.endef
	.def	___cxa_allocate_exception;	.scl	2;	.type	32;	.endef
	.section .drectve

	.ascii " -export:boom"
