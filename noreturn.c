/*Estamos viendo las funciones "noreturn"*/
#include <stdio.h>
#include <stdint.h>
#include <signal.h> ///grandes rasgos, inercomunicacion entre procesos
#include <stdlib.h>

_Noreturn void except();
void violacion(int sig);

int main (void){
	int32_t *aapuntador = NULL;
	signal (SIGSEGV,violacion); ///listener de una eñal, esperando el evento
	////Violacion de segmento
	printf("%d", *aapuntador);
	return 0x1;
}

_Noreturn void except(){
	printf("Morir");
	exit(0);
}

void violacion(int sig){
	except();
}
