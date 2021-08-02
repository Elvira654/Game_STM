#include "stm32f10x.h"                 // Device header
#include "cstdlib" //Za random


void ugasi(){
	for(int i = 16; i < 24; i++)
		GPIOA -> BSRR = (1<<i);
}

//Brojevi
int broj = 0;
int broj2 = 0;

int br[11] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
int er[5] = {0x86, 0xCE, 0xCE, 0xC0, 0xCE};

void randomize(){
	//napravi nove brojeve
	broj = std::rand()%10;
	std::srand(broj+broj);
	broj2 = std::rand()%10;
	
}

void gogogo(){
	for(int tri = 0; tri < 3; tri++){
		ugasi();
		GPIOA->BSRR = br[6];
		for(int i = 0; i < 3000000; i++);
		ugasi();
		GPIOA->BSRR = br[0];
		for(int i = 0; i < 3000000; i++);
	}
}

void errFunct(){
	for(int e = 0; e < 5; e++){
		ugasi();
		GPIOA->BSRR = er[e];
		for(int i = 0; i < 3000000; i++);
	}
}

int main(){
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
	
	//A0 do A7 output
	GPIOA -> CRL = GPIO_CRL_MODE;
	GPIOA -> CRL &= ~GPIO_CRL_CNF;	
	
	//Pinovi b5(vece) i b4(manje) su ulazi
	GPIOB->CRL &= ~GPIO_CRL_MODE5_0;
	GPIOB->CRL &= ~GPIO_CRL_CNF5_1;	
	
	GPIOB -> CRL &= ~GPIO_CRL_MODE4_0;
	GPIOB -> CRL &= ~GPIO_CRL_CNF4_1;	

	std::srand(123456789);
	
	randomize();
	
	gogogo(); //pocetna animacija
	while(1){
		//provjera za vece
		if(GPIOB->IDR & GPIO_IDR_IDR5){
			if(broj > broj2){
				ugasi();
				GPIOA -> BSRR = br[broj];
				for(int i = 0; i < 4000000; i++);
			}
			else{
				ugasi();
				errFunct();
				ugasi();
				GPIOA -> BSRR = br[broj];
				for(int i = 0; i < 4000000; i++);
			}
			randomize();
		}
		
		//Provjeravamo za manje
		if(GPIOB->IDR & GPIO_IDR_IDR4){
			if(broj < broj2){
				ugasi();
				GPIOA -> BSRR = br[broj];
				for(int i = 0; i < 4000000; i++);
			}
			else{
				ugasi();
				errFunct();
				ugasi();
				GPIOA -> BSRR = br[broj];
				for(int i = 0; i < 4000000; i++);
			}
			randomize();
		}
		
		//Uvijek ispisujemo koji broj je to koji poredimo
		ugasi();
		GPIOA -> BSRR = br[broj2];
		for(int i = 0; i < 20000; i++);
		
		
	}
}
