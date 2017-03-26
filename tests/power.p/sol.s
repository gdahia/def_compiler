.data

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

_f_mod:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
b _end_f_mod
_end_f_mod:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 8
addiu $sp, $sp, 8
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_power:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $0, 16($fp)
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 0
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_1
b _fi_1
_if_1:
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
b _end_f_power
_fi_1:
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_2
b _fi_2
_if_2:
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
b _end_f_power
_fi_2:
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_power
sw $a0, 16($fp)
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 16($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
sw $a0, 16($fp)
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_3
b _fi_3
_if_3:
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
sw $a0, 16($fp)
_fi_3:
lw $a0, 16($fp)
b _end_f_power
_end_f_power:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 12
addiu $sp, $sp, 16
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_solve:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_power
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
_end_f_solve:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 12
addiu $sp, $sp, 12
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_main:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -12
li $a0, 10212
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 19212001
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 42
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -12
li $a0, 1290
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 9910291
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 56
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -12
li $a0, 20102
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 920190219
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 109290192
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
_end_f_main:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 0
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

main:
sw $fp, 0($sp)
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall
