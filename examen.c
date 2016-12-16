#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//					funciones		base			alto
#define RECTANGULO sizeof(void*) + sizeof(int) + sizeof(int)
//					functiones		radio
#define CIRCULO sizeof(void*) + sizeof(int)

#define R_BASE sizeof(void*)
#define R_ALTO sizeof(void*) + sizeof(int)

#define C_RADIO sizeof(void*)

//vtables
char rec_vtable[sizeof(void*) + sizeof(int*)*2];
char cir_vtable[sizeof(void*) + sizeof(int*)*2];

//polimorfismo
void print(char* figura){
	void* vtable = *((void**)figura);
	void (*print)();
	print = *((void**)vtable);
	print(figura);
}

int getPerimetro(char* figura){
	void* vtable = *((void**)figura);
	int (*perimetro)();
	perimetro = *((int**)(vtable + sizeof(void*) ));
	return perimetro(figura);
}

int getArea(char* figura){
	void* vtable = *((void**)figura);
	int (*area)();
	area = *((int**)(vtable + sizeof(void*) + sizeof(int*) ));
	return area(figura);
}

//constructores
void rectange_ctr(char * this, int base, int alto){
	*((void**)this) = rec_vtable;
	*((int*)(this + R_BASE)) = base;
	*((int*)(this + R_ALTO)) = alto;
}

void circle_ctr(char * this, int radio){
	*((void**)this) = cir_vtable;
	*((int*)(this + C_RADIO)) = radio;
}

//funciones

int rec_getArea(char* this){
	int base = *((int*)(this + R_BASE));
	int alto = *((int*)(this + R_ALTO));
	return base*alto;
}

int cir_getArea(char* this){
	int radio = *((int*)(this + C_RADIO));
	return 3.14 * (radio*radio);
}

int cir_getPerimetro(char* this){
	int radio = *((int*)(this + C_RADIO));
	return 2*3.14*radio;
}

int rec_getPerimetro(char* this){
	int base = *((int*)(this + R_BASE));
	int alto = *((int*)(this + R_ALTO));
	return 2*base + 2*alto;
}

void cir_print(char* this){
	int radio = *((int*)(this + C_RADIO));
	printf("Circulo -> radio: %d, perimetro: %d, area: %d \n", radio, getPerimetro(this), getArea(this));
}

void rec_print(char* this){
	int base = *((int*)(this + R_BASE)); 
	int alto = *((int*)(this + R_ALTO));
	printf("Rectangulo -> base: %d, alto: %d, perimetro: %d, area: %d \n", base, alto, getPerimetro(this), getArea(this));
}

//vtable setup
void setup_vtable(){
	*((void**)cir_vtable) = &cir_print;
	*((void**)(cir_vtable + sizeof(void*) )) = &cir_getPerimetro;
	*((void**)(cir_vtable + sizeof(void*)  + sizeof(int*) )) = &cir_getArea;

	*((void**)rec_vtable) = &rec_print;
	*((void**)(rec_vtable + sizeof(void*) )) = &rec_getPerimetro;
	*((void**)(rec_vtable + sizeof(void*)  + sizeof(int*) )) = &rec_getArea;
}

char rectangulo1[RECTANGULO];

//main
int main(){
	setup_vtable();

	rectange_ctr(rectangulo1, 2, 3);
	char circulo[CIRCULO];
	circle_ctr(circulo, 5);

	char* rectangulo2 = malloc(RECTANGULO);
	rectange_ctr(rectangulo2, 3, 2);

	print(rectangulo1);
	print(rectangulo2);
	print(circulo);


	free(rectangulo2);

	return 0;
}