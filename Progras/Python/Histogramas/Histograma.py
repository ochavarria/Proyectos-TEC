## Analiza los cortes de un video o una secuencia de imagenes
## Mediante la distancia de Bhattarcharyya, calculando la media y la desviacion
## Estandar de la distancia entre cuadros consecutivos
##
## NOTA: ESTA VERSION NO UTILIZA TENSORFLOW, PERO POSEE UNA VELOCIDAD MUCHISIMO MAYOR QUE CON EL TF INCORPORADO
##
##
## Importacion de librerias necesarias
import numpy as np
import matplotlib.pyplot as plt
import sys,os,cv,cv2,math

##Clase que calcula los histogramas
class Histogramas:
    #Lista de histrogramas de cada cuadro
    l = []
    #lista de distancia entre un cuadro con otro
    g = []
    #Media del arreglo G
    media = 0.0
    #Desviacion estandar del arreglo G
    desviacion = 0.0
    #Cuadros con corte
    u = []
    #Cuadros con corte para realizar la grafica con matplotlib
    uGraph = []
    #Nombre del archivo XML a generar
    xml = None
    
    def video(self,vid,xml):
        """
            Analiza el histograma de cada cuadro en un video

            Parametros
            ----------
            vid : str
                String del video a ser procesado
            xml : str
                String del archivo XML a generar como salida de los cortes

            Returns
            -------
            None
                No retorna nada
        """
        self.xml = xml
        video = cv2.VideoCapture(vid)
        while(video.isOpened()):
            ret, imagen = video.read()
            if (imagen is None):
                break
            im1 = cv2.cvtColor(imagen, cv2.COLOR_BGR2HSV)
            size = len(im1)*len(im1[0])
            im1 = cv2.calcHist([im1],[0],None,[256],[0,256])
            self.l += [im1/(len(im1)*len(im1[0]))]

    def imagen(self,patron,extension,xml):
        """
            Analiza el histograma de cada cuadro en un video

            Parametros
            ----------
            patron : str
                String Del patron del video, la primera parte (Ej: C:/video/Foto-)
            extension : str
                String de la extension de las imagenes (Ej: jpeg)
            xml : str
                String del archivo XML a generar como salida de los cortes

            Returns
            -------
            None
                No retorna nada
        """
        self.xml = xml
        i = 0
        #Revisa hasta encontrar una imagen que no exista
        while(os.path.exists(patron+str(i)+"."+extension)):
            imagen = cv2.imread(patron+str(i)+"."+extension)
            imagen = cv2.resize(imagen, (320, 480)) 
            i+=1
            im1 = cv2.cvtColor(imagen, cv2.COLOR_BGR2HSV)
            size = len(im1)*len(im1[0])
            im1 = cv2.calcHist([im1],[0],None,[256],[0,256])
            self.l += [im1/(len(im1)*len(im1[0]))]
        

    def calcG(self):
        """
            Calcula la distancia de dos histogramas consecutivos
            Returns
            -------
            List
                Retorna una lista con la distancias entre los histogramas
        """
        i = 0
        while i!=len(self.l)-1:
            self.g+=[self.Bhattacharyya(self.l[i],self.l[i+1])]
            i+=1
    def Bhattacharyya(self, hist1,  hist2):
        """
            Analiza la distancia entre 2 histogramas

            Parametros
            ----------
            hist1 : np.Array
                Arreglo de numpy con el histograma del cuadro 1
            hist2 : np.Array
                Arreglo de numpy con el histograma del cuadro 2
        
            Returns
            -------
            float
                Distancia entre los cuadros
        """
        h1_ = np.average(hist1);
        h2_ = np.average(hist2);
        beta = 0.0;
        for i in range(min(len(hist1),len(hist2))):
            beta += math.sqrt( hist1[i] * hist2[i] );
    
        alfa = 1.0/math.sqrt(np.average(hist2)*np.average(hist1)*(min(len(hist1),len(hist2))**2))
        ab = alfa*beta
        return math.sqrt(abs(1-ab));

    def calcMediaDesviacion(self):
        """
            Analiza la media del arreglo g e instancia la variable media y desviacion

        """
        i = 0
        self.media = 0.0
        varianza = 0.0
        while i!=len(self.g):
            self.media += self.g[i]
            varianza += (self.g[i])**2
            i+=1
        self.media = self.media/i
        self.desviacion=math.sqrt(varianza/i)
        
    def arregloU(self):
        """
            Indica cuales secuencias tienen cortes y lo guarda en el arreglo U

        """
        i = 0
        while i!=len(self.g):
            if(self.g[i]>=self.media+self.desviacion):
                self.u+=[[1,i,self.g[i]]]
                self.uGraph+=[[1,i,self.g[i]]]
            else:
                self.u+=[[0,i,self.g[i]]]
            i+=1
        
    def genXML(self):
        """
            Genera el XML indicando los cortes 

        """
        XML = "<cortes>\n"
        for i in self.u:
            if(i[0]==1):
                XML+="     <corte>\n         <cuadros>"+str(i[1])+"->"+str(i[1]+1)+"</cuadros>\n     </corte>\n"
        XML += "</cortes>"
        f = open(self.xml,"w")
        f.write(XML)
        f.close()
    def getU(self):
        """
            Indica el arreglo U
            
            Returns
            -------
            np.Array
                Arreglo U
        """
        return self.uGraph

    def getG(self):
        """
            Indica el arreglo G
            
            Returns
            -------
            np.Array
                Arreglo G
        """
        return self.g
        
    def reset(self):
        """
            Reinicia los parametros

        """
        self.l = []
        self.g = []
        self.media = 0.0
        self.desviacion = 0.0
        self.u = []
        self.uGraph = []

class Principal:
    """
        Clase del menu principal, se encarga de tomar los parametros e iniciar los 

    """
    #Inicia la clase histogramas para realizar los calculos
    histogramas = Histogramas()
    def __init__(self):
        self.menu()
    def menu(self):
        if(0 != -3):
            tipo = input("Tipo a revisar:\n1. Video\n2. Imagenes \nOpcion Seleccionada: ")
            if(tipo == 1):
                video = raw_input("Ruta al video: ")
                xml = raw_input("Archivo salida XML: ")
                self.histogramas.video(video,xml)
                self.histogramas.calcG()
                self.histogramas.calcMediaDesviacion()
                self.histogramas.arregloU()
                self.histogramas.genXML()
                self.histogramas.reset()

            else:
                carpeta = raw_input("Ruta la carpeta: ")
                patronInicio = raw_input("Patron inicio (Ej: 'foto-'): ")
                extension = raw_input("Extension: ")
                xml = raw_input("Archivo salida XML: ")
                self.histogramas.imagen(carpeta+"/"+patronInicio,extension,xml)
                self.histogramas.calcG()
                self.histogramas.calcMediaDesviacion()
                self.histogramas.arregloU()
                self.histogramas.genXML()
                self.histogramas.reset()
        if(raw_input("Analizar otra secuencia [y/n]: ") == "y"):
            self.menu()
        else:
            return


if __name__ == "__main__":
   Principal()
