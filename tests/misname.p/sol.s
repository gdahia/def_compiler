.data
__j: .word 0
__jne: .word 0
__f_main: .word 0
__mul: .word 0
__add: .word 0
__addi: .word 0
__div: .word 0
__li: .word 0
__ra: .word 0
__fn_main: .word 0

.text
_f_print:
lw $a0, 4($sp)
li $v0, 1
syscall
li $v0, 11
li $a0, 0x0a
syscall
addiu $sp, $sp, 4
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_b:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
b _end_f_b
_end_f_b:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
addiu $sp, $sp, 4
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_sw:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
b _end_f_sw
_end_f_sw:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
addiu $sp, $sp, 4
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_var_mul:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, __j
b _end_f_var_mul
_end_f_var_mul:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
addiu $sp, $sp, 4
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_v_addi:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, __jne
b _end_f_v_addi
_end_f_v_addi:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
addiu $sp, $sp, 4
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_main:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_b
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
sw $fp, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
li $a0, 9
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_sw
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
_end_f_main:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 0
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

main:
sw $0, __j
sw $0, __jne
sw $0, __f_main
sw $0, __mul
sw $0, __add
sw $0, __addi
sw $0, __div
sw $0, __li
sw $0, __ra
sw $0, __fn_main
sw $fp, 0($sp)
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall
