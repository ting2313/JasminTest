.class public compiler_hw3
.super java/lang/Object
.field public static a I=6
.field public static b I=0
.method public static main([Ljava/lang/String;)V
	.limit stack 50
	ldc 0
	istore 0
	ldc 2
	ldc 6
	imul
	getstatic compiler_hw3/a I
	iadd
	return
.end method
