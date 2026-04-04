#include "persister.h"
#include <iostream>
#include <fstream>

Persister::Persister(){}
Persister::~Persister(){}
std::string Persister::read(std::string uri){
    return "";
}
void Persister::write(std::string uri,std::string content){
    return;
}


FilePersister::FilePersister(){

}
FilePersister::~FilePersister(){

}

std::string FilePersister::read(std::string uri) {
  std::cout << "FilePersister read() llamado para: " << uri << std::endl;
    
    std::ifstream myfile(uri);
    std::string summary = "";

    if (myfile.is_open()) {
        std::string line;
        // Reservar espacio si el archivo es grande para evitar reasignaciones costosas
        // summary.reserve(1000); 

        while (getline(myfile, line)) {
            summary += line + "\n"; 
        }
        myfile.close();
        
        // Si quieres ver el resultado final, imprímelo UNA SOLA VEZ fuera del bucle
        std::cout << "[ DEBUG ] Lectura finalizada. Tamaño: " << summary.size() << " bytes." << std::endl;

    } else {
        std::cerr << "FilePersister::Read() No se pudo abrir el archivo '" << uri << "'" << std::endl;
    }
    return summary;
}

/**
* std::ios::in	    Input	    Abre para lectura (por defecto en ifstream).
* std::ios::out	    Output	    Abre para escritura (por defecto en ofstream).
* std::ios::app	    Append	    Todas las escrituras ocurren al final del archivo.
* std::ios::ate	    At the end	Abre el archivo y mueve el cursor al final, pero permite moverlo luego (seekp).
* std::ios::trunc	Truncate	Si el archivo existe, borra todo su contenido al abrirlo.
* std::ios::binary	Binary	    Abre en modo binario (evita traducciones de caracteres como \n a \r\n).
* 
*/
void FilePersister::write(std::string uri, std::string content){
    std::cout << "FilePersister write() llamado para: " << uri << std::endl;
    
    std::ofstream myfile(uri,std::ios::app);
    if (myfile.is_open()) {
        myfile << content << "\n";
        myfile.close();
    } else {
        std::cerr << "FilePersister::Write() No se pudo abrir el archivo '" << uri << "'" << std::endl;
    }
}

void FilePersister::write(std::string uri, std::string content, int flag){
    std::cout << "FilePersister write() llamado para: " << uri << std::endl;
    
    std::ofstream myfile(uri,flag);
    if (myfile.is_open()) {
        myfile << content << "\n";
        myfile.close();
    } else {
        std::cerr << "FilePersister::Write() No se pudo abrir el archivo '" << uri << "'" << std::endl;
    }
}

