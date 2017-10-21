#pragma once

#include "DatoTexto.h"
#include "AdministradorArchivo.h"

class EscritorArchivo : public AdministradorArchivo
{
public:

	void abrir(string pRuta, bool pSobrescitura=true);

	void escribir(DatoTexto* pDato);

};
