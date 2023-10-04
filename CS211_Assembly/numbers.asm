# make an assembly program that takes 30 numbers (1-30 exclusive) as input and returns the amount of numbers between 1-10, 11-20, 21-30

.data
array: .space 120
string: .asciiz	"Enter 30 numbers: "
message1: .asciiz "Numbers between 1-10: "
message2: .asciiz "Numbers between 11-20: "
message3: .asciiz "Numbers between 21-30: "
newl: .asciiz "\n"
details: .asciiz "Anilsha T, 4/14/21"


.text
main:
li $v0, 4
la $a0, string
li $t9, 120
li $t0, 0
li $t1, 0
li $t2, 0
li $t3, 0
li $s1, 10
li $s2, 20
li $s3, 30
syscall
li $v0, 4
la $a0, newl
syscall

read_numbers:
	beq $t0, $t9, comparison
	li $v0, 5
	syscall
	sw $v0, array($t0)
	addi $t0, $t0, 4
	j read_numbers
	
comparison:
	li $t0, 0
	while:
		beq $t0, $t9, printMessages
		lw  $s0, array($t0)
		
		
		sle $t5, $s0 ,$s1
		beq $t5, $0, test2
		jal under10 
		
		
	test2:	
		sgt $t6, $s0, $s1
		sle $t7, $s0, $s2
		and $t5, $t6, $t7
		beq $t5, $0, test3
		jal under20
	test3:	
		sgt $t6, $s0, $s2
		sle $t7, $s0, $s3
		and $t5, $t6, $t7
		beq $t5, $0, addlabel
		jal under30

	addlabel:
		addi $t0, $t0,4
		j while


under10:
	addi $t1, $t1, 1
	jr $ra
under20:
	addi $t2, $t2, 1
	jr $ra
under30:
	addi $t3, $t3, 1
	jr $ra

printMessages:
	li $v0, 4
	la $a0, message1
	syscall
	li $v0, 1
	la $a0, ($t1)
	syscall
	li $v0, 4
	la $a0, newl
	syscall


	li $v0, 4
	la $a0, message2
	syscall
	li $v0, 1
	la $a0, ($t2)
	syscall
	li $v0, 4
	la $a0, newl
	syscall


	li $v0, 4
	la $a0, message3
	syscall
	li $v0, 1
	la $a0, ($t3)
	syscall
	li $v0, 4
	la $a0, newl
	syscall
	
	li $v0, 4
	la $a0, details
	syscall
	li $v0, 4
	la $a0, newl
	syscall