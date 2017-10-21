# -*- coding: cp1252 -*-
from Tkinter import *
import re
import random
import tkMessageBox
import urllib2
import smtplib # para envio de correos
from email.mime.text import MIMEText #se importa el modulo email que necesitamos


#################################################################################################################################################################

# Entradas :---
# Salidas :Se registra a un nuevo usuario
# Restricciones :que las contraseñas sean iguales
def CrearCuenta():
    #Construimos una ventana    
    vent=Tk()
    vent.config()
    vent.geometry("625x540")       #Damos el tamaÃƒÂ±o que deseamos de las ventanas
    vent.title("Cuenta")   #Damos el titulo de la ventana principal    
    entrada1=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    entry1=Entry(vent,textvar=entrada1).grid(row=1,column=1)
    entry2=Entry(vent,textvar=entrada2).grid(row=2,column=1)
    entry3=Entry(vent,textvar=entrada3).grid(row=3,column=1)
    entry4=Entry(vent,textvar=entrada4).grid(row=4,column=1)
    #Label
    label=Label(vent,text='Nombre de usuario:').grid(row=1,column=0)
    label=Label(vent,text='Correo:').grid(row=2,column=0)
    label=Label(vent,text='Contrasena:').grid(row=3,column=0)
    label=Label(vent,text='Repita contrasena:').grid(row=4,column=0)

    #E:
    #S:Revisa si todos los datos son validos 
    #R:
    def Revisar():
        
        if entrada1.get()==''or entrada2.get()==''or entrada3.get()=='' or entrada4.get()=='':

            if entrada1.get()==''and entrada2.get()==''and entrada3.get()=='' and entrada4.get()=='':
                label=Label(vent,text='*').grid(row=1,column=2)
                label=Label(vent,text='*').grid(row=2,column=2)
                label=Label(vent,text='*').grid(row=3,column=2)
                label=Label(vent,text='*').grid(row=4,column=2)
                

            elif entrada1.get()=='' and entrada2.get()=='' and entrada3.get()=='':
                label=Label(vent,text='*').grid(row=1,column=2)
                label=Label(vent,text='*').grid(row=2,column=2)
                label=Label(vent,text='*').grid(row=3,column=2)

            elif entrada1.get()==''and entrada2.get()=='' and entrada4.get()=='':
                label=Label(vent,text='*').grid(row=1,column=2)
                label=Label(vent,text='*').grid(row=2,column=2)
                label=Label(vent,text='*').grid(row=4,column=2)

            elif entrada1.get()==''and entrada3.get()=='' and entrada4.get()=='':
                label=Label(vent,text='*').grid(row=1,column=2)
                label=Label(vent,text='*').grid(row=3,column=2)
                label=Label(vent,text='*').grid(row=4,column=2)
                
            elif entrada2.get()==''and entrada3.get()=='' and entrada4.get()=='':
                label=Label(vent,text='*').grid(row=2,column=2)
                label=Label(vent,text='*').grid(row=3,column=2)
                label=Label(vent,text='*').grid(row=4,column=2)




            elif entrada1.get()=='' and entrada2.get()=='' :
                label=Label(vent,text='*').grid(row=1,column=2)
                label=Label(vent,text='*').grid(row=2,column=2)

            elif entrada1.get()=='' and entrada3.get()=='' :
                label=Label(vent,text='*').grid(row=1,column=2)
                label=Label(vent,text='*').grid(row=3,column=2)

            elif entrada1.get()=='' and entrada4.get()=='' :
                label=Label(vent,text='*').grid(row=1,column=2)
                label=Label(vent,text='*').grid(row=4,column=2)

            elif entrada2.get()=='' and entrada3.get()=='' :
                label=Label(vent,text='*').grid(row=2,column=2)
                label=Label(vent,text='*').grid(row=3,column=2)

            elif entrada2.get()=='' and entrada4.get()=='' :
                label=Label(vent,text='*').grid(row=2,column=2)
                label=Label(vent,text='*').grid(row=4,column=2)

            elif entrada3.get()=='' and entrada4.get()=='' :
                label=Label(vent,text='*').grid(row=3,column=2)
                label=Label(vent,text='*').grid(row=4,column=2)

            elif entrada1.get()=='':
                label=Label(vent,text='*').grid(row=1,column=2)

            elif entrada2.get()=='':
                label=Label(vent,text='*').grid(row=2,column=2)                
                
            elif entrada3.get()=='':
                label=Label(vent,text='*').grid(row=3,column=2)            

            elif entrada4.get()=='':
                label=Label(vent,text='*').grid(row=4,column=2)

        else:
            pattern = re.compile("@")
            if re.search('(?<=@)\w+', str(entrada2.get())):
                m=re.search('(?<=@)\w+', str(entrada2.get()))
                m=m.group(0)
                m=str(m)

                if entrada3.get()==entrada4.get():
                    if pattern.search(entrada2.get()) and (m=='hotmail' or m=='gmail' or m=='yahoo'):
            
                        cuenta=open('Cuentas.txt','a')
                        cuenta.write(entrada1.get()+','+entrada2.get()+','+entrada3.get()+','+entrada4.get())
                        mensaje=tkMessageBox.showinfo(message='Solicitud completada')
                        vent.destroy()
                    else:
                        label=Label(vent,text='*').grid(row=2,column=2)


                else:
                    label=Label(vent,text='*').grid(row=3,column=2)
                    label=Label(vent,text='*').grid(row=4,column=2)
            else:
                label=Label(vent,text='*').grid(row=2,column=2)
                






    b1=Button(vent,text="Crear",command=lambda:Revisar()).grid(row=5,column=0)

    label=Label(vent,text='Ingresa los datos solicitados').grid(row=0,column=0)
    vent.mainloop()



#######################################################################################################################################################################

# Entradas :-----
# Salidas : Los datos del txt en listas
# Restricciones : ----
def creacion_final():
    final=open('Deudas.txt','r')
    datos=final.read()
    lista=datos.split('\n')
    lista_de_sublista=creacion(lista,[])
    lista1=lista_de_sublista
    return lista1

def creacion(lista,res):
    if(lista==[]):
        return res
    else:
        partes= lista[0].split(",")

        return creacion(lista[1:],res+[partes])
#######################################################################################################################################################################
# Entradas :-----
# Salidas : Los datos del txt en listas
# Restricciones : ---
def creacion_final2():
    final=open('Cuentas.txt','r')
    datos=final.read()
    lista=datos.split('\n')
    lista_de_sublista=creacion(lista,[])
    lista1=lista_de_sublista
    return lista1

def creacion(lista,res):
    if(lista==[]):
        return res
    else:
        partes= lista[0].split(",")

        return creacion(lista[1:],res+[partes])

#######################################################################################################################################################################
# Entradas : La lista de deudas
# Salidas : Se guarda en una variable res las deudas para almacenarla en el archivo de texto 'Cuenta de Tarjeta de credito'
# Restricciones : ----

def guardar(Deudas):
        CuentaTC=open('Deudas.txt','w')
        while Deudas!=[]:
            res=''
            x=0
            while Deudas[0]!=[]:
                if len (Deudas[0])==1:
                    res=res+Deudas[0][x]+'\n'
                    Deudas[0]=Deudas[0][1:]
                else:
                    res=res+Deudas[0][x]+','
                    Deudas[0]=Deudas[0][1:]
                    
                
            CuentaTC.write(res)
            Deudas=Deudas[1:]                
    
    






#######################################################################################################################################################################
# Entradas : Las deudas
# Salidas : Se cancelan las deudas pendientes
# Restricciones : ------
def Cancelar(Deudas,x,v1):
    Deudas[x][-1]='Pagado'
    guardar(Deudas)
    b2=Button(v1,text ='Pagar',state='disable',command = lambda:Cancelar(Deudas[x])).grid(row=x,column=1,sticky=W)
    

#######################################################################################################################################################################
# Entradas : una ventana, una variable, una lista
# Salidas : se envia la lista a la funcion Info
# Restricciones :--

def Crear(v1,x,Deudas):    
    b1=Button(v1,text = Deudas[x][0],relief='flat',command = lambda:Info(Deudas[x])).grid(row=x,column=0,sticky=W)
    b2=Button(v1,text ='Pagar',command = lambda:Cancelar(Deudas,x,v1)).grid(row=x,column=1,sticky=W)
#######################################################################################################################################################################
# Entradas : una ventana, una variable, una lista
# Salidas : se envia la lista a la funcion Info
# Restricciones :--
def Crear2(v1,x,lista):    
    b1=Button(v1,text = lista[0],relief='flat',command = lambda:Info(lista)).grid(row=x,column=0,sticky=W)

#######################################################################################################################################################################

# Entradas :Una lista, ventana
# Salidas : Los datos que estan pendientes en botones 
# Restricciones : ------

def pagos(Deudas,v1):
    x=0
    y=0
    while x!=len(Deudas):
        if Deudas[x][-1]=='Pendiente':
            Crear(v1,x,Deudas)
            x+=1
            y+=1
        else:
            x+=1
    if y==0:
        Label(v1, text='No tienes Deudas').grid(row=x,column=0,sticky=W)
#######################################################################################################################################################################

# Entradas :Una lista
# Salidas : Se muestra un mensaje con todos los datos de la lista
# Restricciones : ------

def Info(i):
    res=''
    y=0
    
    for x in i:
        if len(i)==7:
            
            if y==0:
                res=res+'ID:'+'\n'+x+'\n'
                y+=1
                
            elif y==1:
                res=res+'Monto:'+'\n'+x+'\n'
                y+=1

            elif y==2:
                res=res+'Dia:'+'\n'+x+'\n'
                y+=1

            elif y==3:
                res=res+'Entidad:'+'\n'+x+'\n'
                y+=1

            elif y==4:
                res=res+'Mes:'+'\n'+x+'\n'
                y+=1

            elif y==5:
                res=res+'Ano:'+'\n'+x+'\n'
                y+=1

            else:  
                res=res+'Estado:'+'\n'+x+'\n'
                y+=1
        else:

            if y==0:
                res=res+'ID:'+'\n'+x+'\n'
                y+=1

            elif y==1:
                res=res+'Cantidad de pagos:'+'\n'+x+'\n'
                y+=1

            elif y==2:
                res=res+'Monto:'+'\n'+x+'\n'
                y+=1

            elif y==3:
                res=res+'Entidad:'+'\n'+x+'\n'
                y+=1

            elif y==4:
                res=res+'Dia:'+'\n'+x+'\n'
                y+=1

            elif y==5:
                res=res+'Mes:'+'\n'+x+'\n'
                y+=1

            elif y==6:
                res=res+'Ano:'+'\n'+x+'\n'
                y+=1

            else:  
                res=res+'Estado:'+'\n'+x+'\n'
                y+=1
            
    mensaje=tkMessageBox.showinfo(message=res)
#######################################################################################################################################################################

# Entradas :Una lista
# Salidas : Se muestra un mensaje con todos los datos de la lista
# Restricciones : ------

def Info2(i):
    res=''
    y=0
    
    for x in i:
        if len(i)==7:
            
            if y==0:
                res=res+'ID:'+'\n'+x+'\n'
                y+=1
                
            elif y==1:
                res=res+'Monto:'+'\n'+x+'\n'
                y+=1

            elif y==2:
                res=res+'Dia:'+'\n'+x+'\n'
                y+=1

            elif y==3:
                res=res+'Entidad:'+'\n'+x+'\n'
                y+=1

            elif y==4:
                res=res+'Mes:'+'\n'+x+'\n'
                y+=1

            elif y==5:
                res=res+'Ano:'+'\n'+x+'\n'
                y+=1

            else:  
                res=res+'Estado:'+'\n'+x+'\n'
                y+=1
        else:

            if y==0:
                res=res+'ID:'+'\n'+x+'\n'
                y+=1

            elif y==1:
                res=res+'Cantidad de pagos:'+'\n'+x+'\n'
                y+=1

            elif y==2:
                res=res+'Monto:'+'\n'+x+'\n'
                y+=1

            elif y==3:
                res=res+'Entidad:'+'\n'+x+'\n'
                y+=1

            elif y==4:
                res=res+'Dia:'+'\n'+x+'\n'
                y+=1

            elif y==5:
                res=res+'Mes:'+'\n'+x+'\n'
                y+=1

            elif y==6:
                res=res+'Ano:'+'\n'+x+'\n'
                y+=1

            else:  
                res=res+'Estado:'+'\n'+x+'\n'
                y+=1
    return res


#######################################################################################################################################################################
# Entradas :Una ventana
# Salidas : Se paga la deuda
# Restricciones :---

def Pagar(vent):
    Deudas=creacion_final()
    v1 = Toplevel(vent)
    v1.title('Pagos')
    pagos(Deudas,v1)


   
            
            


#######################################################################################################################################################################
# Entradas : entidad, estado de la cuenta, la ventana, el tipo de moneda
# Salidas : Se realiza la busqueda
# Restricciones :----

def BuscarC(Entidad,estado,v1,tipo):
    v2=Toplevel(v1)
    v2.title('Resultados')
    Deudas=creacion_final()
    res=[]
    for i in Deudas:
        if i==['']:
            print
            

        else:            
            if i[3]==Entidad and i[-1]==estado:
                res+=[i]


    if res==[]:
            Label(v2, text='No se encontraron Resultados').grid(row=100,column=0,sticky=W)
    else:                        
        x=0
        for i in res:
            Crear2(v2,x,i)
            x+=1

        total=0
        for i in res:
            if len(i)==7:
                total+=int(i[1])
            else:
                total+=int(i[2])

        if tipo=='Colones':
            total=str(total)
            Label(v2, text='Monto total de :').grid(row=100,column=0,sticky=W)
            Label(v2, text=total).grid(row=100,column=1,sticky=W)
            Buscar= Button(v2, text = 'Enviar a correo', command = lambda:SendMail(res)).grid(row=100,column=2,sticky=W)

        else:
            response = urllib2.urlopen('http://indicadoreseconomicos.bccr.fi.cr/indicadoreseconomicos/Cuadros/frmVerCatCuadro.aspx?CodCuadro=400')
            html = response.read()
            x=html[29856:29859]
            y=html[29860:29862]
            x=x+'.'+y
            x=float(x)
            total=total/x
            total=str(total)+'$'
            Label(v2, text='Deuda total:').grid(row=100,column=0,sticky=W)
            Label(v2, text=total).grid(row=100,column=1,sticky=W)
            Correo= Button(v2, text = 'Enviar a correo', command = lambda:SendMail(res)).grid(row=100,column=2,sticky=W)
            
            

#######################################################################################################################################################################
# Entradas : ventana, tipo de moneda
# Salidas : Se efectua la consulta
# Restricciones : ----
def Consulta(vent,tipo):
    v1 = Toplevel(vent)
    v1.title('Consulta ')
    Label(v1, text='Complete lo solicitado para la busqueda').grid(row=0,column=0,sticky=W)
    
    banco=Label(v1, text='Elija su banco : ').grid(row=1,column=0,sticky=W)
    menubar = Menu(v1)
    v1.config(menu=menubar)
    scroll_1 = StringVar()
    bancos = ['BNCR','BCR','BP','BAC','CITI','SCOTIA','BCAC','BSOL','CATAY']
    scroll_1DropDown = OptionMenu(v1, scroll_1, *bancos).grid(row=1,column=1,sticky=W)

    
    Estado=Label(v1, text='Elija el estado : ').grid(row=2,column=0,sticky=W)
    scroll_2 = StringVar()
    Estados = ['Pendiente','Pagado']
    scroll_1DropDown = OptionMenu(v1, scroll_2, *Estados).grid(row=2,column=1,sticky=W)
    

    Buscar= Button(v1, text = 'Buscar', command = lambda:BuscarC(scroll_1.get(),scroll_2.get(),v1,tipo)).grid(row=3,column=0,sticky=W)


#######################################################################################################################################################################
    
#E:Una lista
#S:El envio del correo con los datos
#R:


def SendMail(res):
    envio=''
    for i in res:
        envio+=Info2(i)

    user=creacion_final2()
    username=user[0][1]
    password=user[0][2]
    mailServer = smtplib.SMTP('smtp.live.com')
    mailServer.ehlo()
    mailServer.starttls()
    
    mailServer.login(username,password)
    msg = MIMEText(envio)
    msg['Subject'] = 'Consulta de deudas'
    msg['From'] = username
    msg['To'] = username
    
    mailServer.sendmail( username, username, msg.as_string())
    mailServer.close()











    
#######################################################################################################################################################################
# Entradas : Monto en colones, datos de registros de fecha
# Salidas : Se registra la tarjeta de credito
# Restricciones : datos debern ser enteros
def registrarTC(ColonesMonto,scroll_1,scroll_2,scroll_3,scroll_4):
    if ColonesMonto.get()=='' or scroll_1.get()=='' or scroll_2.get()=='' or scroll_3.get()=='' or scroll_4.get()=='':
        mensaje=tkMessageBox.showinfo(message='No dejar ningun campo en blanco')
    else:
            
            
        ID=Identificador()
        CuentaTC=open('Deudas.txt','a')
        deuda=ID+','+ColonesMonto.get()+','+scroll_2.get()+','+scroll_1.get()+','+scroll_3.get()+','+scroll_4.get()+','+'Pendiente'+'\n'
        CuentaTC.write(deuda)
        CuentaTC.close()

#######################################################################################################################################################################
# Entradas : Numero de cuotas, monto de cuotas, datos de fecha 
# Salidas : Se registra el prestamo
# Restricciones :----
def registrarPrest(NumCoutas,MontoCuota,CantidadCuota,scroll_1,scroll_2,scroll_3,scroll_4):
    if CantidadCuota=='' or scroll_1=='' or scroll_2=='' or scroll_3=='' or scroll_4=='' or NumCoutas=='' or MontoCuota=='':
        mensaje=tkMessageBox.showinfo(message='No dejar ningun campo en blanco')
    else:
        if int(NumCoutas)<int(CantidadCuota):
             mensaje=tkMessageBox.showinfo(message='La cantidad de cuotas no puede \n ser mayor al numero de cuotas')
        else:
            return registrarPrestaux(NumCoutas,MontoCuota,CantidadCuota,scroll_1,scroll_2,scroll_3,scroll_4)

def registrarPrestaux(NumCoutas,MontoCuota,CantidadCuota,scroll_1,scroll_2,scroll_3,scroll_4):
        if CantidadCuota==0:
            return
        else:
            ID=Identificador()
            CuentaPrest=open('Deudas.txt','a')
            deuda=ID+','+NumCoutas+','+MontoCuota+','+scroll_1+','+scroll_2+','+scroll_3+','+scroll_4+','+'Pendiente'+'\n'
            CuentaPrest.write(deuda)
            CuentaPrest.close()
            CantidadCuota=int(CantidadCuota)-1
            if int(scroll_3)==12:
                scroll_3=str(1)
                scroll_4=str(int(scroll_4)+1)
                return registrarPrestaux(NumCoutas,MontoCuota,CantidadCuota,scroll_1,scroll_2,scroll_3,scroll_4)
            else:
                scroll_3=str(int(scroll_3)+1)
                return registrarPrestaux(NumCoutas,MontoCuota,CantidadCuota,scroll_1,scroll_2,scroll_3,scroll_4)

#######################################################################################################################################################################

# Entradas : ---
# Salidas : Se muestra el identificador de usuario si el identicador no estaba en la lista que contenia informacion del archivo de texto
# Restricciones :---
def Identificador():
    final=open('Identificadores.txt','r')
    datos=final.read()
    lista=datos.split('\n')
    ident=ID()
    if ident not in lista:
        lista=lista+[ident]
        mensaje=tkMessageBox.showinfo(message='Tu identificador es '+ident)
        Guardar(lista)
        return ident
    else:
        return Identificador()
#######################################################################################################################################################################
# Entradas : Una lista
# Salidas : Se guarda en un archivo de texto la informacion de una lista
# Restricciones :---
def Guardar(lista):
    final=open('Identificadores.txt','w')
    for i in lista :
        i='\n'+i
        final.write(i)
    final.close()
    return 
#######################################################################################################################################################################
# Entradas :----
# Salidas : Un string
# Restricciones :----        
def ID():
    caractrs = ['a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','v','V','w','W','x','X','y','Y','z','Z','1','2','3','4','5','6','7','8','9']
    ID = ''
    i=0
    while i<4:
        ran = random.choice(caractrs)
        ID+=ran
        i+=1
            
    return ID



#######################################################################################################################################################################

#Interfaz de Registro(partir de
#una tarjeta de crÃ©dito)

# Entradas : Una ventana
# Salidas : Se registra mediante  tarjeta de credito
# Restricciones :  


def CardCreditRegister(v0):
    v1 = Toplevel(v0)
    v1.geometry('600x500+0+0')
    v1.title('CardCredit')
    v1.resizable(0,0)
   
    #monto de pago
    ColonesMonto = StringVar()
    Monto = Label(v1, text='Monto de pago: ').grid(row=0,column=0,sticky=W)
    entry = Entry(v1, textvariable=ColonesMonto).grid(row=0,column=1,sticky=W)
    
    #entidad financiera
    banco=Label(v1, text='Elija su banco : ').grid(row=1,column=0,sticky=W)
    menubar = Menu(v1)
    v1.config(menu=menubar)
    scroll_1 = StringVar()
    bancos = ['BNCR','BCR','BP','BAC','CITI','SCOTIA','BCAC','BSOL','CATAY']
    scroll_1DropDown = OptionMenu(v1, scroll_1, *bancos).grid(row=1,column=1,sticky=W)

   #Fecha de pago de la obligacion
    fecha = Label(v1, text = 'Fecha de pago:').grid(row=2,column=0,sticky=W)
    
    #Dia:
    scroll_2 = StringVar()
    scroll_2.set('Dia')
    Dia = ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31']
    scroll_2DropDown = OptionMenu(v1, scroll_2, *Dia).grid(row=2,column=1,sticky=W)

    #Mes:
    scroll_3 = StringVar()
    scroll_3.set('Mes')
    Mes = ['1','2','3','4','5','6','7','8','9','10','11','12']
    scroll_3DropDown = OptionMenu(v1, scroll_3, *Mes).grid(row=2,column=2,sticky=W)

    #Ano:
    scroll_4 = StringVar()
    scroll_4.set('Ano')
    Ano = ['2014','2015','2016','2017','2018','2019','2020','2021','2022','2023','2024']
    scroll_4DropDown = OptionMenu(v1, scroll_4, *Ano).grid(row=2,column=3,sticky=W)   
      
    Registrar = Button(v1, text = 'Registrar', command = lambda:registrarTC(ColonesMonto,scroll_1,scroll_2,scroll_3,scroll_4)).grid(row=6,column=0,sticky=W)
#######################################################################################################################################################################
# Entradas : Una ventana
# Salidas : Se guarda los datos del prestamo
# Restricciones :  


def RegistrarPrestamo(vent):
    v1=Toplevel(vent)
    v1.geometry('600x500+0+0')
    v1.title('Prestamo')
    
    NumCoutas = StringVar()
    Label(v1, text='Numero de cuotas del prestamo: ').grid(row=0,column=0,sticky=W)
    entry1 = Entry(v1, textvariable=NumCoutas).grid(row=0,column=1,sticky=W)

    MontoCuota = StringVar()
    Label(v1, text='Pago por cada cuota: ').grid(row=1,column=0,sticky=W)
    entry2 = Entry(v1, textvariable=MontoCuota).grid(row=1,column=1,sticky=W)
    
    #entidad financiera
    banco=Label(v1, text='Elija su banco : ').grid(row=2,column=0,sticky=W)
    menubar = Menu(v1)
    v1.config(menu=menubar)
    scroll_1 = StringVar()
    bancos = ['BNCR','BCR','BP','BAC','CITI','SCOTIA','BCAC','BSOL','CATAY']
    scroll_1DropDown = OptionMenu(v1, scroll_1, *bancos).grid(row=2,column=1,sticky=W)

   #Fecha de pago de la obligacion
    fecha = Label(v1, text = 'Fecha de pago de la cuota :').grid(row=4,column=0,sticky=W)

    #Dia:
    scroll_2 = StringVar()
    scroll_2.set('Dia')
    Dia = ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31']
    scroll_2DropDown = OptionMenu(v1, scroll_2, *Dia).grid(row=4,column=1,sticky=W)

    #Mes:
    scroll_3 = StringVar()
    scroll_3.set('Mes')
    Mes = ['1','2','3','4','5','6','7','8','9','10','11','12']
    scroll_3DropDown = OptionMenu(v1, scroll_3, *Mes).grid(row=4,column=2,sticky=W)

    #Ano:
    scroll_4 = StringVar()
    scroll_4.set('Ano')
    Ano = ['2014','2015','2016','2017','2018','2019','2020','2021','2022','2023','2024']
    scroll_4DropDown = OptionMenu(v1, scroll_4, *Ano).grid(row=4,column=3,sticky=W)

    CantidadCuota = StringVar()
    Label(v1, text='Cantidad de cuotas que desea registrar: ').grid(row=5,column=0,sticky=W)
    entry3 = Entry(v1, textvariable=CantidadCuota).grid(row=5,column=1,sticky=W)
    

    
      
    Registrar = Button(v1, text = 'Registrar', command = lambda:registrarPrest(NumCoutas.get(),MontoCuota.get(),CantidadCuota.get(),scroll_1.get(),scroll_2.get(),scroll_3.get(),scroll_4.get())).grid(row=6,column=0,sticky=W)
    
    





#################################################################################################################################################################
#E:
#S:Una ventana
#R:
def principal():
    #Construimos una ventana
    cuenta=open('Cuentas.txt','r')
    cuenta=cuenta.read()
    if cuenta=='':
        return CrearCuenta()
    else:
        vent=Tk()
        vent.config()
        vent.geometry("625x540")       #Damos el tamaÃƒÂ±o que deseamos de las ventanas
        vent.title('Check Bills')   #Damos el titulo de la ventana principal

         
        b1=Button(vent,text="Registrar una obligación de crédito (tarjeta de crédito)",command=lambda:CardCreditRegister(vent)).grid(row=2,column=0,sticky=W)
        b2=Button(vent,text="Registrar una obligación de crédito (Prestamo)",command=lambda:RegistrarPrestamo(vent)).grid(row=3,column=0,sticky=W)
        b3=Button(vent,text="Consignar pago de obligación crediticia",command=lambda:Pagar(vent)).grid(row=4,column=0,sticky=W)
        b4=Button(vent,text="Consultas de obligaciones crediticias",command=lambda:Consulta(vent,'Colones')).grid(row=5,column=0,sticky=W)
        b5=Button(vent,text="Consultas de obligaciones crediticias (En dolares)",command=lambda:Consulta(vent,'Dolares')).grid(row=6,column=0,sticky=W)
        b6=Button(vent,text="Salir",command=lambda:vent.destroy()).grid(row=7,column=0,sticky=W)




        
        vent.mainloop() #funcion obligatoria para que corra la interfaza
principal()


