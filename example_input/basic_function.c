int foo(int a) {
   a += 6;
   return a;
}

void lol(int b) {
    print(b);
	return;
}

void main(){
   int a;
   a = foo(4);
   lol(a);
   return;
}
