int test1() {
  int a,b;
  a = 1;
  b = a+2;
  a = 3;
  b = a+4;
  return a+b;
}


int test2() {
  int a,b;
  if (a<1) { b =1;} else { b = 2;}
  a = b;
  return a+b;
}

int test3() {
  int a,b;
  b = 1;
  while (a<1) { b = b + 1; }
  return a+b;
}

int test4() {
  int a,b;
  if (a<1) { if (a<2) b=1; else b=2; }
  else b = 3;
  return a+b;
}
  
  
int main() { return 0; }
