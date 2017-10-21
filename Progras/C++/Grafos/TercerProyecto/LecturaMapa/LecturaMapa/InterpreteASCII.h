#pragma once

//Class con informacion de la Tabla ascii que permite clasificar lo leido en un archivo por medio de char
class InterpreteASCII
{
public:

	enum valoresASCIIRelevantes { NULO = -1, CAMBIOLINEA = 10, ESPACIO = 32, COMA = 44, PUNTO = 46, DOSPUNTOS = 58, PUNTOYCOMA };

	bool esCaracter(char pDato);
	bool esNumero(char pDato);
	bool esSeparador(char pDato);

};
