#Oscar Chavarria Campos
#2014088971

import random
import math
import cmath
import timeit

#Numero 1 de la progra.
#E:Una lista 
#S: Una lista con numeros complejos 
#R: Tiene que ser una lista de N>0
def LaDiscreta(Lista):
    FN = []#Lista final
    N= len(Lista)#Largo de la lista 
    Xn =  (cmath.e)**((-2j*cmath.pi)/N)#El mult con el complejo
    Xa= 1   
    for k in range(0,N):
        Xk=0
        Xf = 1
        for i in range(0,N):
            Xk = Xk + (Lista [i] * Xf)# El centro de la funcion 
            Xf = Xf * Xa            
        Xa = Xa * Xn# Se introduce el numero complejo
        FN.append(round(Xk.real) + round(Xk.imag)*1j)#Se agrega al resultado final
        #Se redondea ambas partes y se mulp por un complejo para que el resultado
        #Sea mas agradable a la vista a la hora de hacer las pruebas 
    return FN
        
#Numero 2 de la progra
#E:Una lista con numeros compejos 
#S: Una lista con sus elementos invertidos.
#R: Tiene que ser una lista de N>0
def LaInvdeDiscreta(Lista):
    FN = []
    N= len(Lista)
    for k in range(0,N):
        Xk=0
        for i in range(0,N):
            Xk +=Lista [i]*((cmath.e)**(2j * cmath.pi * k * i / N))# El centro de la funcion 
        Xk=(Xk/N)
        FN.append(round(Xk.real))
        #Se agrega al resultado final
        #Se redondea ambas partes para que
        #Sea mas agradable a la vista a la hora de hacer las pruebas 
    return FN



#Numero 4 de la progra
#E:Una lista 
#S: Una lista con numeros complejos
#R: Tiene que ser una lista de N>0
def LaCooleyTk(Lista):
    N=len(Lista)
    Pares=[]
    Impares=[]
    if N==1:
        return Lista
    else:
        for i in range(N):# Se divide la lista en pares e impares 
            if i%2==0:
                Pares.append(Lista[i])
            else:
                Impares.append(Lista[i])
        P=[]
        Im=[]
        P=LaDiscreta(Pares)# Se saca la discreta a ambas partes
        Im=LaDiscreta(Impares)
        result=[]
        X=[]
        for r in range(N):
            X.append(0)# Se inicializa la variable para que a la hora de ingresar los indices no de error
        for k in range(N//2):
            X[k]= P[k] + Im[k] * (cmath.e **(-2j*cmath.pi*k /N))# El centro de la funcion 1 
            X[k + N//2] = P[k] - Im[k] * (cmath.e **(-2j*cmath.pi*k /N)) # El centro de la funcion 1 
        return X
# Funciones para resolver la pregunta 5

#E:Un numero
#S: El tiempo de ejecucion de de la descreta con una lista de N largo
#R: Tiene que ser una lista de N>0
def TDiscreta(N):  # Funcion para calcular la duracion de la discreta
    Lista=[]
    rest=[]
    for i in range(N):# Se hace un random ya que se ocupa calcular listas de largo 2**N
        Lista.append(i)

    inicio= timeit.default_timer()#Se setea el tiempo en cero e incia reloj
    rest= LaDiscreta(Lista)# Se hace la llamada
    final = timeit.default_timer()#Lee el tiempo que duro. 
    
    r="%.16f"%(final-inicio)# Devuelve el tiempo en segundos
    return r

#E:Un numero
#S: El tiempo de ejecucion de de la Lacooley con una lista de N largo
#R: Tiene que ser una lista de N>0
def TCooley(N):  # Funcion para calcular la duracion de Cooley
    Lista=[]
    rest=[]
    for i in range(N):# Se hace un random ya que se ocupa calcular listas de largo 2**N
        Lista.append(i)
   
    inicio= timeit.default_timer()#Se setea el tiempo en cero e incia reloj
    rest= LaCooleyTk(Lista)# Se hace la llamada
    final = timeit.default_timer()#Lee el tiempo que duro. 
    
    r="%.16f"%(final-inicio)# Devuelve el tiempo en segundos
    return r

        
