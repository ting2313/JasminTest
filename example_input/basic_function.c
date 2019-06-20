int foo(int a) {
   a += 6;
   return a;
}

int add(int a,int b,int c) {
   int d = b+c;
   return d;
}

void lol(int b) {
    print(b);
	return;
}

void main(){
   int a= add(10,3,5);
   lol(a);
   return;
}
