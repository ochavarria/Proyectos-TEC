from ParserR import *
import os
import decimal

tabla = []

def printTabla():
  for i in tabla:
    print"----------------------------------------"
    print i[0]+"\t\t"+i[1]
    

class compilador(object):
  pathCodigo = ""
  codigo = ""

  def __init__(self, archivo):
    try:
      self.pathCodigo = archivo
      self.codigo = open(archivo).read()+"\n"
    except:
      codigo = None
      pass

  def compilar(self, filename = "<string>"):
    try:
        return
    except Exception as err:
            print (err)

  def revisarTokens(self, imprimir=0):
    try:
      x = lexxer()
      x.RevisarTokens(self.codigo)
      
    except Exception as err:
            print(err)

  def revisarGramatica(self, imprimir = 0):
    arbol = Paarser()
    try:
      a = arbol.RevisarGramatica(self.codigo)
      print 'La gramatica esta correcta'
    except Exception as err:
      print err


  def imprimirTablaDeSimbolos(self):
    try:
            c = self.revisarGramatica()
            obtenerTablaSimbolos(c)
            printTabla()
    except:
            print "No se ha podido generar la tabla!"
    

  def setCodigo(self, archivo):
    try:
            self.pathCodigo = archivo
            self.codigo = open(archivo).read()+"\n"
            print (self.codigo)
            
    except:
            print "No se ha podido abrir el archivo"
            codigo = None
  
            
  def quitarExtension(self, archivo):
    x = ""
    for i in archivo:
            if i == ".":
                    break
            x+=i
    return x
  
  def generarCodigoAsm(self):
    try:
      return 
    except Exception as err:
      print err

  def revisarCodigo(self):
    return self.codigo!=None

  def recargarCodigo(self):
    try:
            self.codigo = open(self.pathCodigo).read()+"\n"
    except:
            print("No se ha podido recargar su codigo")


c = compilador("")

    
def imprimirMenu():
	print "Por favor seleccione una opcion:"
	print "0. Ingresar codigo"
	print "1. Recargar codigo"
	print "2. Revisar Tokens"
	print "3. Imprimir Tokens"
	print "4. Revisar gramatica"
	print "5. Ver arbol generado por parser"
	print "6. Imprimir Tabla de simbolos"
	print "7. Generar codigo asm"
	print "8. Compilar / ejecutar"
	print "9. Salir"

def menu():
  try:
    imprimirMenu()
    opcion = int(input("Por favor seleccione una opcion: "))
    if opcion == 0:
      archivo = raw_input("Ingrese la ruta del archivo: ")
      c.setCodigo(archivo)
      
    elif opcion == 1:
      c.recargarCodigo()
      
    else:
      if(not c.revisarCodigo()):
        print "No se ha cargado ningun codigo"
        
      else:
        if opcion == 2:
          c.revisarTokens(0)
        elif opcion == 3:
          c.revisarTokens(1)
        elif opcion == 4:
          c.revisarGramatica(0)
        elif opcion == 5:
          c.revisarGramatica(1)
        elif opcion == 6:
          c.imprimirTablaDeSimbolos()
        elif opcion == 7:
          c.generarCodigoAsm()
        elif opcion == 8:
          print "\n"
          c.compilar()
        elif opcion == 9:
          return
        else:
          raise Exception("")
  except:
    print "Por favor ingrese solo opciones validas!"
  raw_input("\n\nPresione enter para continuar...")
  os.system('clear')
  menu()
	
#x = compilador()
menu()
