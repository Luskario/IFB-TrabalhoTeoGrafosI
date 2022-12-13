#include <iostream>
#include <fstream>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "./libs/processamento.h"

using namespace std;

bool criar_diretorio(string nome){

    string nomeDir = "./output/" + nome;

    struct stat st = {0};
	
	if (stat(nomeDir.c_str(), &st) == -1) {
		if(mkdir(nomeDir.c_str(), 0700) == 0){
			return true;
		}
	}		
	
	return false;
}

bool esperar(int tempo){
	int temp_inicial = clock();

	while(clock()-temp_inicial < tempo){

	}
	return true;
}
