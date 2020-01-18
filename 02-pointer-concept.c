#include <stdio.h>

void callByValue(int p, int q) {
	p++; q++;
	printf("yeni degerler %d, %d\n",p,q);
}

void callByReference(int *p, int *q) {
	(*p)++; (*q)++;
	printf("yeni degerler %d, %d\n", *p, *q);
}

void value(int *p, int *q) {
	(*p)++; (*q)++;
	printf("p ve q nun degerleri %d, %d\n", p, q);
}

int main() {
	int a[] = { 1,2,3 };
	for (int i = 0; i < 3; i++) {
		printf("a nin degeri = %d\n", a[i]);
		printf("a nin adresi = %u\n", &a[i]);
	}

	printf("\n");

	int x = 2;
	int *y, **z;
	y = &x;
	//z = &x; yapamayiz, cunku a'nin icinde deger var, adres yok
	z = &y;
	// &a = b = *c ve &b = c olur
	printf("x, y ve z = %d, %d, %d\n", &x, y, *z);
	printf("x, y ve z = %d, %d, %d\n", x, y, *z);
	printf("x, y ve z = %d, %d, %d\n", x, *y, *z);
	printf("x, y ve z = %d, %d, %d\n", x, *y, **z);

	printf("\n");

	// deger ile cagirma
	int m = 2;
	int n = 1;
	printf("deger ile cagirilmadan once %d, %d\n", m, n);
	callByValue(m, n);
	printf("deger ile cagirildiktan sonra %d, %d\n", m, n);

	printf("\n");

	// referans ile cagirma
	printf("referans ile cagirilmadan once %d, %d\n", m, n);
	callByReference(&m, &n);
	printf("referans ile cagirildiktan sonra %d, %d\n", m, n);

	printf("\n");

	printf("m ve n nin adresleri %d, %d\n", &m, &n);
	value(&m,&n);

	return 0;
}