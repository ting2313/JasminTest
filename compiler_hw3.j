.class public compiler_hw3
.super java/lang/Object
.method public static foo(I)I
.limit stack 50
.limit locals 50
	iload 0
	ldc 6
	swap
	iadd
	istore 0
	iload 0
	ireturn
.end method
.method public static add(III)I
.limit stack 50
.limit locals 50
	iload 2
	iload 1
	swap
	iadd
	istore 3
	iload 3
	ireturn
.end method
.method public static lol(I)V
.limit stack 50
.limit locals 50
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 10
	ldc 3
	ldc 5
	invokestatic compiler_hw3/add(III)I
	istore 0
	iload 0
	invokestatic compiler_hw3/lol(I)V
	return
.end method
