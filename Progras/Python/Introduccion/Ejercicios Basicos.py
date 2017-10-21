def suma(a, b):
    print("Entro a la funcion de Suma")
    return a+b

def resta(a, b):
    print("Entro a la funcion de Resta")
    return a-b

def multi(a, b):
    print("Entro a la funcion de Multi")
    return a*b

def div(a, b):
    print("Entro a la funcion de Div")
    return a/b

def estado_est(nota):
    if (nota>=70):
        return 'Aprobado'
    elif(nota>=60 and nota<=69):
        return 'Aplazado'
    else:
        return 'Reprobado'

def nombre_completo():
    nombre=input('Digite su nombre: ')
    apellido1=input('Ingres su primer apellido: ')
    apellido2=input('Por ultimo, escriba su segundo apellido: ')
    print('Su nombre completo es: ',nombre,apellido1,apellido2)


def calculadora():
    print('CALCULADORA CUENTA POLLOS')
    print("1.Suma - 2.Resta - 3.Multi - 4.Div")
    op=input("Digite la opcion: ")
    num1=int(input("digite numero 1: "))
    num2=int(input('digite numero 2: '))
    if (op=='1'):
        r=num1+num2
        print("el resultado de la suma es: ",r)
    elif (op=='2'):
        r=num1-num2
        print("el resultado de la resta es: ",r)
    elif (op=='3'):
        r=num1*num2
        print("el resultado de la multiplicacion es: ",r)
    else:
        r=num1/num2
        print("el resultado de la division es: ",r)

def calculadora2():
    print('CALCULADORA CUENTA POLLOS V2')
    print("1.Suma - 2.Resta - 3.Multi - 4.Div")
    op=input("Digite la opcion: ")
    num1=int(input("digite numero 1: "))
    num2=int(input('digite numero 2: '))
    if (op=='1'):
        r=suma(num1,num2)
        print("el resultado de la suma es: ",r)
    elif (op=='2'):
        r=resta(num1,num2)
        print("el resultado de la resta es: ",r)
    elif (op=='3'):
        r=multi(num1,num2)
        print("el resultado de la multiplicacion es: ",r)
    else:
        r=div(num1,num2)
        print("el resultado de la division es: ",r)

def obtener_medio(n1, n2, n3):
    lista_num = [n1, n2, n3]
    num_min = min(lista_num)
    num_max = max(lista_num)
    if(lista_num[0] != num_min and lista_num[0] != num_max):
        print ("El numero medio es:", lista_num[0])
    elif(lista_num[1] != num_min and lista_num[1] != num_max):
        print ("El numero medio es:", lista_num[1])    
    else:
        print ("El numero medio es:", lista_num[2])

def ultimo_digito(num):
    ult_dig = num%10
    return ult_dig


def suma_digitos(num):
    if(num>99 and num<1000):
        import math
        unidad = math.floor(num%10)
        num = math.floor(num/10)
        decena = math.floor(num%10)
        num = math.floor(num/10)
        centena = num
        suma = centena+decena+unidad
        print(suma)
    else:
        print("Error no cumplen la restriccion")


##------- Ejercicios -----------##

#1
def div(dig, num):
    import math
    if (isinstance(dig, int) and isinstance(num, int)):
        if(0<dig<10 and 1000<=num<10000):
            n1=str(math.floor((num%10)/dig))
            num=num//10
            n2=str(math.floor((num%10)/dig))
            num=num//10
            n3=str(math.floor((num%10)/dig))
            num=num//10
            n4=str(math.floor((num%10)/dig))
            print(int(n4+n3+n2+n1))
        else:
            print("Error: entrdas no son validas")

    else:
        print("Error: debe digitar un num entero")


#2
def es_bisiesto(anno):
    if(isinstance(anno, int)):
        if(anno%4==0 and (anno%100!=0 or anno%400==0)):
            print(anno, "es bisiesto")
        else:
            print(anno, "no es bisiesto")
    else:
        print("anno no valido")

#3

def son_impares(num):
    if(isinstance(num, int)):
        dig = num%10
        if(dig%2!=0):
            num=num//10
            dig=num%10
            if(dig%2!=0):
                num=num//10
                dig=num%10
                if(dig%2!=0):
                    print("Los digitos son impares")
                else:
                    print("No todos son impares")
            else:
                print("No todos son impares")
        else:
            print("No todos son impares")
    else:
        print("Error: entrada no valida")



##------- Ejercicios 3 -----------##

def invertir(num):
    if(isinstance(num, int)):
        if(0<=num<=9):
            print(num)
        elif(10<=num<=99):
            print(str(num%10)+str(num//10))
        elif(100<=num<=999):
            print(str(num%10)+str((num//10)%10)+str((num//10)//10))
        else:
            print("Error: Fuera de rango")
    else:
        print("Error: no es numero")


def par_impar(num):
    if(isinstance(num, int)):
        if(0<=num<=9):
            u = es_par_impar(num)
            print(u)
        elif(10<=num<=99):
            u = es_par_impar(num%10)
            d = es_par_impar(num//10)
            print(d+'-'+u)
        elif(100<=num<=999):
            u = es_par_impar(num%10)
            d = es_par_impar((num//10)%10)
            c = es_par_impar((num//10)//10)
            print(c+'-'+d+'-'+u)
        else:
            print("Error: Fuera de rango")
    else:
        print("Error: no es numero")


def es_par_impar(num):
    if(num%2==0):
        return 'par'
    else:
        return 'impar'



#Quiz 1

def sustituir(dig, pos, num):
    import math
    if(isinstance(dig, int) and isinstance(pos, int) and (isinstance(num, int))):
        if(0<=pos<=2 and 100<=num<=999):
            u=num%10
            d=(num//10)%10
            c=((num//10)//10)%10
            if(pos==2):
                print(str(c)+str(d)+str(dig))
            elif(pos==1):
                print(str(c)+str(dig)+str(u))
            else:
                print(str(dig)+str(d)+str(u))
        else:
            print("Error")
    else:
        print("Error: entrada no son numeros")

        

## ------------ Recursividad ------------ ##

def factorial(num):
    if (num==0):
        return 1
    else:
        return num*factorial(num-1)
    

def fibonnaci(num):
    if (num==0):
        return 0
    elif (num==1):
        return 1
    else:
        return (fibonnaci(num-1)+fibonnaci(num-2))


def sumatoria(num):
    if(num==0):
        return 0
    else:
        return(num+sumatoria(num-1))


def cuenta_pares(num):
    if(num==0):
        return 1
    else:
        return cuenta_pares_aux(num)


def cuenta_pares_aux(num):
    if(num==0):
        return 0
    else:
        if((num%10)%2==0):
            return 1+ cuenta_pares_aux(num//10)
        else:
            return cuenta_pares_aux(num//10)


##------- Ejercicios 4 -----------##

def ordenado(num):
    if(num<10):
        return True
    else:
        return ordenado_aux(num)

def ordenado_aux(num):
    if(num==0):
        return True
    else:
        if((num//10)%10 <= num%10):
            return ordenado_aux(num//10)
        else:
            return False



# Función: ceros
# Entradas: número
# Salidas: indicador boolean si el número contiene un cero
# Restricciones: número debe ser entero
def ceros(num):
    if isinstance(num, int):
        if num != 0:
            return ceros_aux(abs(num))
        else:
            return True
    else:
        return "Error: numero debe ser entero"
        
def ceros_aux(num):
    if num == 0: # condición de terminación 1
        return False # valor de retorno
    elif(num% 10) == 0: # condición de terminación 2
        return True # valor de retorno
    else:
        return ceros_aux(num // 10)



def contar_dig(num):
    if(isinstance(num, int)):
        if(num<10):
            return num
        else:
            return contar_dig_aux(num)
    else:
        return "Error, NO es numero"

def contar_dig_aux(num):
    if(num==0):
        return 0
    else:
        return num%10+contar_dig_aux(num//10)



def primo(num):
    if(num==0 or num==1):
        return False
    else:
        return primo_aux(num, 2)
    
def primo_aux(num, div):
    if(num==div):
        return True
    else:
        if((num%div)==0):
            return False
        else:
            return primo_aux(num,div+1)



##------ Quiz 2 -------

#1
def apariciones(dig, num):
    if(isinstance(num,int) and isinstance(num,int) and dig<10):
        return apariciones_aux(dig,abs(num))
    else:
        return "error"

def apariciones_aux(dig,num):
    if (num==0):
        return 0
    else:
        if (num%10==dig):
            return 1+apariciones_aux(dig,num//10)
        else:
            return apariciones_aux(dig,num//10)



#2
def elevar(x,n):
    if(isinstance(x,int) and isinstance(n,int)):
        if(x==0):
            return 0
        elif(n==0):
            return 1
        else:
            return elevar_aux(x,n)
    else:
        return"error"
    
def elevar_aux(x,n):
    if(n==0):
        return 1
    else:
        return x*elevar_aux(x,n-1)


##··········· Recursividad cola ·············##

def fact_cola(n):
    if (isinstance(n, int) and n>=0):
        return fact_cola_aux(n,1)
    

    else:
        print("Error n no es entero")

def fact_cola_aux(n, res):
    if(n==0):
        return res
    else:
        return fact_cola_aux(n-1,res*n)
    

def sum_cola(n):
    if (isinstance(n,int) and n>0):
        return sum_cola_aux(n,0)
    else:
        print("Error n no es entero")

def sum_cola_aux(n, res):
    if (n==0):
        return res
    else:
        return sum_cola_aux(n-1, res+n)



## Ejercicio Clasificar num: Perfecto, Abundante, Deficiente

def clasifique(num):
    if(isinstance (num, int) and num>0):
        suma = suma_div (num, 1)
        if(num==suma and num!=1):
            return 'Perfecto'
        elif (suma<num):
            return 'Deficiente'
        else:
            return 'Abundante'
    else:
        return 'Error'

def suma_div(num, div):
    if(div>num//2):
        return 0
    elif(num%div==0):
        return div + suma_div(num, div+1)
    else:
        return suma_div(num, div+1)



## Multiplicar Elementos de una lista

def mul_lista(lista):
    if (lista==[]):
        return 0
    else:
        return mul_lista_aux(lista, 1)

def mul_lista_aux(lista, res):
    if(lista==[]):
        return res
    else:
        return mul_lista_aux(lista[1:],res*lista[0])



## Obtner los numeros pares de una lista

def lista_pares(lista):
    if(lista==[]):
        return []
    else:
        return lista_pares_aux(lista, [])

def lista_pares_aux(lista, lista_res):
    if(lista==[]):
        return lista_res
    else:
        if(lista[0]%2==0):
            return lista_pares_aux(lista[1:], lista_res + [lista[0]])
        else:
            return lista_pares_aux(lista[1:], lista_res)
    
            











    
