from tkinter import *
#Botones de la ventana Agregar Referencias
#Con estas funciones podemos llamar las ventanas de las diferentes formas que deseemos
def agregar(ventana): 
    vent=Toplevel(ventana) #El toplevel nos permite crear ventanas hijas de la ventana principal
    vent.config()
    vent.geometry("600x400")
    texto = Label(vent,text="Elija que tipo de referencia desea agregar") #Con label colocamos los mensajes en pantalla deseados
    texto.grid(row=0,column=1)  #Con .grid hacemos que el label creado aparesca en nuestra ventana
    boton = Button(vent,text="Referencia de libros",command=lambda : agregar1(ventana))  #con  button creamos un boton y con command y lambda llamamos una funcion ya creada para darcela al boton
    boton.grid(row=2,column=0)   #Con column decimos en que columna de la pantalla queremos que aparezca y con row en la fila que queramos
    boton2=Button(vent,text="Referencia de tesis",command=lambda :  agregar2(ventana))
    boton2.grid(row=4,column=0)
    boton3=Button(vent,text="Referencia online",command=lambda :  agregar3(ventana))
    boton3.grid(row=6,column=0)
    boton4= Button(vent,text="Articulo de Periodico",command=lambda :  agregar4(ventana))
    boton4.grid(row=8,column=0)
    boton5= Button(vent,text="Articulo Técnicos de Conferencia",command=lambda :  agregar5(ventana))
    boton5.grid(row=10,column=0)
    
    
#Referencia de Libros
##Tomo todos los valores del cuadro de texto y los une con su respectivo formato y lo muestra al usuario
##Entrado: Cuadros de texto
##Salida:El formato ya listo de la referencia
def agregar1(ventana):
    def mostrar():
        apellido=entrada.get() #Con .get podemos guardar la informacion del cuadro de texto en una variable
        autor=entrada2.get()
        año=entrada3.get()
        titulo=entrada4.get()
        ciudad=entrada5.get()
        pais=entrada6.get()
        editorial=entrada7.get()
        resultado=(apellido+','+autor+'.'+'('+año+')'+'.'+titulo+'.'+ciudad+','+pais+':'+editorial) #En la variable resultado unimos la informacion de los cuadros de texto       
        resultado3=("libros"+','+apellido+','+autor+','+año+','+titulo+','+ciudad+','+pais+','+editorial)
        resultado2=(autor+'.'+apellido+'.'+titulo+'.'+ciudad+':'+editorial+','+año+".")
        resultado4=("libros"+','+autor+','+apellido+','+titulo+','+ciudad+','+editorial+','+año)
        result=Label(ventanita,text="Formato APA: "+resultado).grid(row=8,column=0)  #En este label mostramos en pantalla como se est guardando las referencias
        result=Label(ventanita,text="Formato IEEE: "+resultado2).grid(row=9,column=0)
        def guardar(resultado,resultado3):
            archivo=open('APA.txt','a')
            archivo.write('\n'+resultado)
            archivo2=open('APA2.txt','a')
            archivo2.write('\n'+resultado3)
            archivo.close()
            archivo2.close()
        btn=Button(ventanita,text="Guardar cita APA",command=lambda:guardar(resultado,resultado3))
        btn.grid(row=10,column=2)
        def guardar2(resultado2,resultado4):
            archivo=open('IEEE.txt','a')
            archivo.write('\n'+resultado2)
            archivo=open('IEEE2.txt','a')
            archivo.write('\n'+resultado4)
            archivo.close()
        btn2=Button(ventanita,text="Guardar cita IEEE",command=lambda:guardar2(resultado2,resultado4))
        btn2.grid(row=11,column=2)
        
       
                    
            
            
    ventanita=Toplevel(ventana)
    ventanita.config()
    ventanita.geometry("600x500+0+0")
    ventanita.title("Agregando Referencias de Libros")
    etiqueta=Label(ventanita,text='Digite lo que se le solicita',font=('Times New Roman',14)).grid(row=0,column=0)
    etiqueta1=Label(ventanita,text='Apellido del autor:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta2= Label(ventanita,text='Iniciales del autor:',font=('Arial',14),fg='black').grid(row=2,column=0,sticky=W)
    etiqueta3= Label(ventanita,text='Año de publicacion:',font=('Arial',14),fg='black').grid(row=3,column=0,sticky=W)
    etiqueta4= Label(ventanita,text='Titulo del libro:',font=('Arial',14),fg='black').grid(row=4,column=0,sticky=W)
    etiqueta5= Label(ventanita,text='Cuidad donde se publico:',font=('Arial',14),fg='black').grid(row=5,column=0,sticky=W)
    etiqueta6= Label(ventanita,text='Pais donde se publico:',font=('Arial',14),fg='black').grid(row=6,column=0,sticky=W)
    etiqueta7= Label(ventanita,text='Nombre de la editoria:',font=('Arial',14),fg='black').grid(row=7,column=0,sticky=W)

    #Creando un campo de texto
    #set es para asignarle algo al campo
    entrada=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    entrada5=StringVar()
    entrada6=StringVar()
    entrada7=StringVar()
    campo=Entry(ventanita,textvariable=entrada).grid(row=1,column=1)
    campo2=Entry(ventanita,textvariable=entrada2).grid(row=2,column=1)
    campo3=Entry(ventanita,textvariable=entrada3).grid(row=3,column=1)
    campo4=Entry(ventanita,textvariable=entrada4).grid(row=4,column=1)
    campo5=Entry(ventanita,textvariable=entrada5).grid(row=5,column=1)
    campo6=Entry(ventanita,textvariable=entrada6).grid(row=6,column=1)
    campo7=Entry(ventanita,textvariable=entrada7).grid(row=7,column=1)

    #Agarrar lo del campo de texto
    boton= Button(ventanita,text='mostrar',command=mostrar).grid(row=10,column=0)


#Referencia de Tesis
##Tomo todos los valores del cuadro de texto y los une con su respectivo formato y lo muestra al usuario
##Entrado: Cuadros de texto
##Salida:El formato ya listo de la referencia

def agregar2(ventana):
    def mostrar():
        apellido=entrada.get()
        autor=entrada2.get()
        titulo=entrada3.get()
        grado=entrada4.get()
        universidad=entrada5.get()
        ciudad=entrada6.get()
        pais=entrada7.get()
        año=entrada8.get()
        resultado=(apellido+','+autor+'.'+'('+año+')'+'.'+titulo+'.'+grado+','+universidad+','+ciudad+','+pais)
        resultado3=("Tesis"+','+apellido+','+autor+','+año+','+titulo+','+grado+','+universidad+','+ciudad+','+pais)
        resultado2=(autor+"."+apellido+","+titulo+","+grado+".,"+universidad+".,"+ciudad+","+pais+","+año+".")
        resultado4=("Tesis"+','+autor+","+apellido+","+titulo+","+grado+","+universidad+","+ciudad+","+pais+","+año)
        result=Label(vent1,text="En formato APA   :"+resultado).grid(row=8,column=0)
        result=Label(vent1,text="En formato IEEE   :"+resultado2).grid(row=9,column=0)
        def guardar_tesis(resultado,resultado3):
            archivo=open("APA.txt","a")
            archivo.write('\n'+resultado)
            archivo.close()
            archivo2=open("APA2.txt","a")
            archivo2.write('\n'+resultado3)
            archivo2.close()
        boton=Button(vent1,text="Guadar tesis en APA",command=lambda:guardar_tesis(resultado,resultado3))
        boton.grid(row=11,column=2)
        def guardar_tesis2(resultado2,resultado4):
            archivo=open("IEEE.txt","a")
            archivo.write('\n'+resultado2)
            archivo.close()
            archivo2=open("IEEE2.txt","a")
            archivo2.write('\n'+resultado4)
            archivo2.close()
        boton2=Button(vent1,text="Guadar tesis en IEEE",command=lambda:guardar_tesis2(resultado2,resultado4))
        boton2.grid(row=12,column=2)
            

    vent1=Toplevel(ventana)
    vent1.geometry("900x500+0+0")
    vent1.title("Agregando Referencias de Tesis")
    etiqueta=Label( vent1,text='Apellido del Autor:',font=('Arial',14)).grid(row=0,column=0,sticky=W)
    etiqueta2=Label( vent1,text='Iniciales del Autor:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta3=Label(vent1,text='Titulo de la tesis:',font=('Arial',14)).grid(row=2,column=0,sticky=W)
    etiqueta4=Label(vent1,text='Tesis de (Grado academico) no publicada:',font=('Arial',14)).grid(row=3,column=0,sticky=W)
    etiqueta5=Label(vent1,text='Nombre de la Universidad',font=('Arial',14)).grid(row=4,column=0,sticky=W)
    etiqueta6=Label(vent1,text='Cuidad de la publicacion:',font=('Arial',14)).grid(row=5,column=0,sticky=W)
    etiqueta7=Label(vent1,text='Pais de la publicacion:',font=('Arial',14)).grid(row=6,column=0,sticky=W)
    etiqueta8=Label(vent1,text='Año de la publicacion:',font=('Arial',14)).grid(row=7,column=0,sticky=W)

    entrada=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    entrada5=StringVar()
    entrada6=StringVar()
    entrada7=StringVar()
    entrada8=StringVar()
    campo=Entry(vent1,textvariable=entrada).grid(row=0,column=1)
    campo2=Entry(vent1,textvariable=entrada2).grid(row=1,column=1)
    campo3=Entry(vent1,textvariable=entrada3).grid(row=2,column=1)
    campo4=Entry(vent1,textvariable=entrada4).grid(row=3,column=1)
    campo5=Entry(vent1,textvariable=entrada5).grid(row=4,column=1)
    campo6=Entry(vent1,textvariable=entrada6).grid(row=5,column=1)
    campo7=Entry(vent1,textvariable=entrada7).grid(row=6,column=1)
    campo8=Entry(vent1,textvariable=entrada8).grid(row=7,column=1)

    #Agarrar lo del campo de texto
    boton= Button(vent1,text='mostrar',command=mostrar).grid(row=10,column=0)

#Referencia  Online
##Tomo todos los valores del cuadro de texto y los une con su respectivo formato y lo muestra al usuario
##Entrado: Cuadros de texto
##Salida:El formato ya listo de la referencia

def agregar3(ventana):
    def mostrar():
        direccion=entrada.get()
        titulo=entrada2.get()
        autor=entrada3.get()
        año=entrada4.get()
        inicial=entrada5.get()
        resultado=(autor+'.'+'('+año+')'+'.'+titulo+'.'+'Recuperado de '+direccion)
        resultado3=("Online"+','+autor+','+año+','+titulo+','+direccion)
        resultado2=(autor+','+inicial+','+"("+año+")"+','+"¨"+titulo+"¨"+","+'Recuperado de '+direccion)
        resultado4=("Online"+","+autor+','+inicial+','+año+','+titulo+","+direccion)
        result=Label(vent2,text="Formato APA   :"+resultado).grid(row=5,column=0)
        result2=Label(vent2,text="Formato IEEE   :"+resultado2).grid(row=6,column=0)
        def guardar_R_online(resultado,resultado3):
            archivo=open('APA.txt','a')
            archivo.write('\n'+resultado)
            archivo.close()
            archivo2=open('APA2.txt','a')
            archivo2.write('\n'+resultado3)
            archivo2.close()
        boton=Button(vent2,text="Guardar cita APA",command=lambda:guardar_R_online(resultado,resultado3))
        boton.grid(row=4,column=2)
        def guardar_R_online2(resultado2,resultado4):
            archivo=open('IEEE.txt','a')
            archivo.write('\n'+resultado2)
            archivo.close()
            archivo2=open('IEEE2.txt','a')
            archivo2.write('\n'+resultado4)
            archivo2.close()
        boton2=Button(vent2,text="Guardar cita IEEE",command=lambda:guardar_R_online2(resultado2,resultado4))
        boton2.grid(row=5,column=2)
        

    
    vent2=Toplevel(ventana)
    vent2.config()
    vent2.geometry("800x500+0+0")
    vent2.title("Agregando Referencias de articulos online")
    etiqueta=Label(vent2,text='Direccion web:',font=('Arial',14)).grid(row=0,column=0,sticky=W)
    etiqueta2=Label(vent2,text= 'Titulo de la pagina:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta3=Label(vent2,text='Apellido del Autor de pagina:',font=('Arial',14)).grid(row=2,column=0,sticky=W)
    etiqueta4=Label(vent2,text='Fecha de acceso:',font=('Arial',14)).grid(row=3,column=0,sticky=W)
    etiqueta5=Label(vent2,text="Inicial del nombre:",font=('Arial',14)).grid(row=4,column=0,sticky=W)
    entrada=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    entrada5=StringVar()
    campo=Entry(vent2,textvariable=entrada).grid(row=0,column=1)
    campo2=Entry(vent2,textvariable=entrada2).grid(row=1,column=1)
    campo3=Entry(vent2,textvariable=entrada3).grid(row=2,column=1)
    campo4=Entry(vent2,textvariable=entrada4).grid(row=3,column=1)
    campo5=Entry(vent2,textvariable=entrada5).grid(row=4,column=1)
    boton= Button(vent2,text='mostrar',command=mostrar).grid(row=8,column=0)

#Referencia de Periodicos
##Tomo todos los valores del cuadro de texto y los une con su respectivo formato y lo muestra al usuario
##Entrado: Cuadros de texto
##Salida:El formato ya listo de la referencia
def agregar4(ventana):
    def mostrar():
        apellido=entrada.get()
        autor=entrada2.get()
        año=entrada3.get()
        titulo=entrada4.get()
        nombre=entrada5.get()
        pagina=entrada6.get()
        mes=entrada7.get()
        resultado=(apellido+','+autor+'.'+'('+año+')'+'.'+titulo+'.'+nombre+','+'pp.'+pagina)
        resultado3=("Periodicos"+","+apellido+','+autor+','+año+','+titulo+','+nombre+','+pagina)
        resultado2=(autor+'.'+apellido+','+"¨"+nombre+","+'¨'+titulo+','+pagina+","+'pp.'+","+mes+".,"+año+".")
        resultado4=("Periodicos"+","+autor+','+apellido+','+nombre+","+titulo+','+pagina+","+mes+","+año)
        result=Label(vent3,text="Formato APA:"+resultado).grid(row=7,column=0)
        result=Label(vent3,text="Formato IEEE:"+resultado2).grid(row=8,column=0)

        def guardar_periodico(resultado,resultado3):
            archivo=open('APA.txt','a')
            archivo.write('\n'+resultado)
            archivo.close()
            archivo2=open('APA2.txt','a')
            archivo2.write('\n'+resultado3)
            archivo2.close()
        boton=Button(vent3,text="Guardar cita APA",command=lambda:guardar_periodico(resultado,resultado3))
        boton.grid(row=10,column=2)
        def guardar_periodico2(resultado2,resultado4):
            archivo=open('IEEE.txt','a')
            archivo.write('\n'+resultado2)
            archivo.close()
            archivo2=open('IEEE2.txt','a')
            archivo2.write('\n'+resultado4)
            archivo2.close()
        boton2=Button(vent3,text="Guardar cita IEEE",command=lambda:guardar_periodico2(resultado2,resultado4))
        boton2.grid(row=11,column=2)


        
    vent3=Toplevel(ventana)
    vent3.config()
    vent3.geometry("800x500+0+0")
    vent3.title("Agregando Referencias de periodicos")
    etiqueta=Label(vent3,text='Apellido del Autor:',font=('Arial',14)).grid(row=0,column=0,sticky=W)
    etiqueta2=Label(vent3,text='Iniciales del Autor:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta3=Label(vent3,text='Año de publicacion:',font=('Arial',14)).grid(row=2,column=0,sticky=W)
    etiqueta4=Label(vent3,text='Titulo del articulo:',font=('Arial',14)).grid(row=3,column=0,sticky=W)
    etiqueta5=Label(vent3,text='Nombre del Periodico',font=('Arial',14)).grid(row=4,column=0,sticky=W)
    etiqueta6=Label(vent3,text='Paginas del articulo:',font=('Arial',14)).grid(row=5,column=0,sticky=W)
    etiqueta7=Label(vent3,text='Mes de la publicación:',font=('Arial',14)).grid(row=6,column=0,sticky=W)
    entrada=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    entrada5=StringVar()
    entrada6=StringVar()
    entrada7=StringVar()
    campo=Entry(vent3,textvariable=entrada).grid(row=0,column=1)
    campo2=Entry(vent3,textvariable=entrada2).grid(row=1,column=1)
    campo3=Entry(vent3,textvariable=entrada3).grid(row=2,column=1)
    campo4=Entry(vent3,textvariable=entrada4).grid(row=3,column=1)
    campo5=Entry(vent3,textvariable=entrada5).grid(row=4,column=1)
    campo6=Entry(vent3,textvariable=entrada6).grid(row=5,column=1)
    campo7=Entry(vent3,textvariable=entrada7).grid(row=6,column=1)
    boton= Button(vent3,text='Mostrar',command=mostrar).grid(row=9,column=0)


#Articulos tecnicos de conferencia
##Tomo todos los valores del cuadro de texto y los une con su respectivo formato y lo muestra al usuario
##Entrado: Cuadros de texto
##Salida:El formato ya listo de la referencia
def agregar5(ventana):
    def mostrar():
        apellido=entrada.get()
        autor=entrada2.get()
        año=entrada3.get()
        titulo=entrada4.get()
        ciudad=entrada5.get()
        pagina=entrada6.get()
        numero=entrada7.get()
        resultado=(apellido+','+autor+'.'+'('+año+')'+'.'+titulo+'.'+"(Informe Núm."+numero+")"+"."+ciudad+".")
        resultado3=("Conferencias"+","+apellido+','+autor+','+año+','+titulo+','+numero+","+ciudad)
        resultado2=(autor+'.'+apellido+','+"¨"+titulo+","+'¨'+"Conf"+'.,'+ciudad+","+año+","+'pp.'+pagina+".")
        resultado4=("Conferencias"+","+autor+','+apellido+','+titulo+","+ciudad+","+año+","+pagina)
        result=Label(vent4,text="Formato APA:"+resultado).grid(row=7,column=0)
        result=Label(vent4,text="Formato IEEE:"+resultado2).grid(row=8,column=0)

        def guardar_conferencia(resultado,resultado3):
            archivo=open('APA.txt','a')
            archivo.write("\n"+resultado)
            archivo.close()
            archivo2=open("APA2.txt","a")
            archivo2.write("\n"+resultado3)
            archivo2.close()
        boton=Button(vent4,text="Guardar cita APA",command=lambda:guardar_conferencia(resultado,resultado3))
        boton.grid(row=11,column=2)
        def guardar_conferencia2(resultado2,resultado4):
            archivo=open("IEEE.txt","a")
            archivo.write("\n"+resultado2)
            archivo.close()
            archivo2=open("IEEE2.txt","a")
            archivo2.write("\n"+resultado4)
            archivo2.close()
        boton2=Button(vent4,text="Guardar cita IEEE",command=lambda:guardar_conferencia2(resultado2,resultado4))
        boton2.grid(row=12,column=2)


        
    vent4=Toplevel(ventana)
    vent4.config()
    vent4.geometry("800x500+0+0")
    vent4.title("Agregando Referencias de Articulos Técnicos de Conferencia")
    etiqueta=Label(vent4,text='Apellido del Autor:',font=('Arial',14)).grid(row=0,column=0,sticky=W)
    etiqueta2=Label(vent4,text='Iniciales del Autor:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta3=Label(vent4,text='Año de publicacion:',font=('Arial',14)).grid(row=2,column=0,sticky=W)
    etiqueta4=Label(vent4,text='Titulo del articulo:',font=('Arial',14)).grid(row=3,column=0,sticky=W)
    etiqueta5=Label(vent4,text='Ciudad de creación del artículo',font=('Arial',14)).grid(row=4,column=0,sticky=W)
    etiqueta6=Label(vent4,text='Paginas utilizadas:',font=('Arial',14)).grid(row=5,column=0,sticky=W)
    etiqueta7=Label(vent4,text='Número de informe:',font=('Arial',14)).grid(row=6,column=0,sticky=W)
    entrada=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    entrada5=StringVar()
    entrada6=StringVar()
    entrada7=StringVar()
    campo=Entry(vent4,textvariable=entrada).grid(row=0,column=1)
    campo2=Entry(vent4,textvariable=entrada2).grid(row=1,column=1)
    campo3=Entry(vent4,textvariable=entrada3).grid(row=2,column=1)
    campo4=Entry(vent4,textvariable=entrada4).grid(row=3,column=1)
    campo5=Entry(vent4,textvariable=entrada5).grid(row=4,column=1)
    campo6=Entry(vent4,textvariable=entrada6).grid(row=5,column=1)
    campo7=Entry(vent4,textvariable=entrada7).grid(row=6,column=1)
    boton= Button(vent4,text='Mostrar',command=mostrar).grid(row=9,column=0)


#################################################################################################################################################################
#Eliminar Referencias de APA
##E:La informacion del documento txt
##S:El documento modificado
def eliminar(ventana):
    import codecs
    import os
    v0 =Toplevel(ventana)
    v0.config(bg="black")
    v0.resizable(0,0)
    def doit(f): v0.after(100, f)
    def imprimir(textcontrol):print(extcontrol.get('1.0', END+'-1c'))
    def escribir_en_archivo(enlace):
        f = codecs.open(enlace,"w","utf-8")
        texto = t1.get('1.0', END+'-1c')
        f.write(texto)
        f.close()
    def abrir_archivo(enlace):
        if os.path.exists(enlace):
            f = open(enlace,"r")
            h= f.read()
            t1.insert(END,h)
            f.close()
    t1=Text(v0)
    t1.config()
    t1.pack()
    b1 = Button(v0,text="Guardar",command=lambda: doit(escribir_en_archivo('APA.txt')))
    b1.config(bg="black",fg="white")
    b1.pack()
    abrir_archivo('APA.txt')
    v0.mainloop()


#Eliminar Referencias de IEEE
##E:La informacion del documento txt
##S:El documento modificado
def eliminar2(ventana):
    import codecs
    import os
    v0 =Toplevel(ventana)
    v0.config(bg="black")
    v0.resizable(0,0)
    def doit(f): v0.after(100, f)
    def imprimir(textcontrol):print(extcontrol.get('1.0', END+'-1c'))
    def escribir_en_archivo(enlace):
        f = codecs.open(enlace,"w","utf-8")
        texto = t1.get('1.0', END+'-1c')
        f.write(texto)
        f.close()
    def abrir_archivo(enlace):
        if os.path.exists(enlace):
            f = open(enlace,"r")
            h= f.read()
            t1.insert(END,h)
            f.close()
    t1=Text(v0)
    t1.config()
    t1.pack()
    b1 = Button(v0,text="Guardar",command=lambda: doit(escribir_en_archivo('IEEE.txt')))
    b1.config(bg="black",fg="white")
    b1.pack()
    abrir_archivo('IEEE.txt')
    v0.mainloop()
#################################################################################################################################################################    
#Ver Referencias de APA
##E:La informacion del txt
##S:La misma informacion del txt
def ver(ventana):
    import os
    def abrir_archivo(enlace):
        if os.path.exists(enlace):
            f = open(enlace,"r")
            h= f.read()
            t1.insert(END,h)
            f.close()
    vent=Toplevel(ventana)
    vent.config(bg="black")
    vent.resizable(0,0)
    t1=Text(vent)
    t1.config()
    t1.pack()
    abrir_archivo('APA.txt')
    vent.mainloop()
#Ver Referencias de IEEE    
##E:La informacion del txt
##S:La misma informacion del txt
def ver2(ventana):
    import os
    def abrir_archivo(enlace):
        if os.path.exists(enlace):
            f = open(enlace,"r")
            h= f.read()
            t1.insert(END,h)
            f.close()
    vent=Toplevel(ventana)
    vent.config(bg="black")
    vent.resizable(0,0)
    t1=Text(vent)
    t1.config()
    t1.pack()
    abrir_archivo('IEEE.txt')
    vent.mainloop()



######################################Modo Consulta de APA#####################################################
def consulta(ventana):
    def filtros():
        Apellido=entrada.get()
        titulo=entrada2.get()
        Fecha=entrada3.get()
        general=entrada4.get()
        lista=creacion_final()
        print(lista)
        if(Apellido==''and(titulo!='')and(Fecha!='')):
            x=buscando_FyT(lista,titulo,Fecha)
            y=creacion_final2(x,'')
            P=Label(vent2,text=y).grid(row=4,column=0)
            return P
        elif(titulo==''and(Apellido!='')and(Fecha!='')):
            x=buscando_AyF(lista,Fecha,Apellido)
            y=creacion_final2(x,'')
            P=Label(vent2,text=y).grid(row=4,column=0)
            return P
        elif(Fecha==''and(Apellido!='')and(titulo!='')):
            x=buscando_AyT(lista,titulo,Apellido)
            y=creacion_final2(x,'')
            P=Label(vent2,text=y).grid(row=4,column=0)
            return P
        elif(Apellido==''and(titulo=='')and(Fecha!='')):
            x=buscando_Fecha(lista,Fecha)
            y=creacion_final2(x,'')
            P=Label(vent2,text=y).grid(row=4,column=0)
            return P
        elif(titulo!=''and(Apellido=='')and(Fecha=='')):
            x=buscando_Titulo(lista,titulo)
            y=creacion_final2(x,'')
            P=Label(vent2,text=y).grid(row=4,column=0)
            return P
        elif(Fecha==''and(Apellido!='')and(titulo=='')):
            x=buscando_Apellido(lista,Apellido)
            y=creacion_final2(x,'')
            P=Label(vent2,text=y).grid(row=4,column=0)
            return P
        
        elif(Fecha==''and(Apellido=='')and(titulo=='')and(general!="")):
            x=buscador_general(lista,general)
            y=creacion_final2(x,'')
            P=Label(vent2,text=y).grid(row=11,column=0)
            return P
        
        elif(Fecha==''and(Apellido=='')and(titulo=='')):
            P=Label(vent2,text='Favor ingresar datos').grid(row=4,column=0)
            return P
        
        else:
            x=buscando_AyTyF(lista,titulo,Apellido,Fecha)
            y=creacion_final2(x,'')
            P=Label(vent2,text=y).grid(row=4,column=0)
            return P


    vent2=Toplevel(ventana)
    vent2.config()
    vent2.geometry("1000x500+0+0")
    vent2.title("Agregando Referencias")
    etiqueta=Label(vent2,text='Bienvenido al menu de busqueda llene los espacio que desea buscar',font=('Arial',14)).grid(row=0,column=2,sticky=W)
    etiqueta2=Label(vent2,text= 'Apellido del Autor:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta3=Label(vent2,text='Titulo de la pagina:',font=('Arial',14)).grid(row=2,column=0,sticky=W)
    etiqueta4=Label(vent2,text='Fecha:',font=('Arial',14)).grid(row=3,column=0,sticky=W)
    entrada=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    campo2=Entry(vent2,textvariable=entrada).grid(row=1,column=1,sticky=W)
    campo3=Entry(vent2,textvariable=entrada2).grid(row=2,column=1,sticky=W)
    campo4=Entry(vent2,textvariable=entrada3).grid(row=3,column=1,sticky=W)
    campo5=Entry(vent2,textvariable=entrada4).grid(row=10,column=1,sticky=W)
    boton= Button(vent2,text='Buscar',command=filtros).grid(row=5,column=0)
    boton2= Button(vent2,text='Buscador General',command=filtros).grid(row=10,column=0)


#################################################################################################################################################################

#Crear la Lista APA
def creacion_final():
    final=open('APA2.txt','r')
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
#Crear la lista IEEE
def creacion_final4():
    final=open('IEEE2.txt','r')
    datos=final.read()
    lista=datos.split('\n')
    lista_de_sublista=creacion2(lista,[])
    lista1=lista_de_sublista
    return lista1

def creacion2(lista,res):
    if(lista==[]):
        return res
    else:
        partes= lista[0].split(",")
        return creacion2(lista[1:],res+[partes]) 
#################################################################################################################################################################

#Volver a poner la cita bien paramostrar en pantalla en formato APA
  
def creacion_final2(x,res):
    if (x==[]):
        return res
    else:
        y=x
        if (y[0]=='libros'):
            return creacion_final2(x[1:],res+str(y[1]+','+y[2]+'.'+'('+y[3]+')'+'.'+y[4]+'.'+x[5]+','+y[6]+':'+y[7])+'\n')
        elif(y[0]=='Tesis'):
            return creacion_final2(x[1:],res+str(y[1]+','+y[2]+'.'+'('+y[3]+')'+'.'+y[4]+'.'+y[5]+','+y[6]+','+y[7]+','+y[8])+'\n')
        elif(y[0]=='Periodicos'):
            return creacion_final2(x[1:],res+str(y[1]+','+y[2]+'.'+'('+y[3]+')'+'.'+y[4]+'.'+y[5]+','+'pp.'+y[6])+'\n')
        elif(y[0]=='Online'):
            return creacion_final2(x[1:],res+str(y[1]+'.'+'('+y[2]+')'+'.'+y[3]+'.'+'Recuperado de '+y[4])+'\n')
        elif(y[0]=='Conferencias'):
            return creacion_final2(x[1:],res+str(y[1]+','+y[2]+'.'+'('+y[3]+')'+'.'+y[4]+'.'+"(Informe Núm."+y[5]+")"+"."+y[6]+".")+'\n')
        else:
            return creacion_final2(x[1:],res)

#Volver a poner la cita bien paramostrar en pantalla en formato IEEE

def creacion_final3(x,res):
    if (x==[]):
        return res
    else:
        y=x
        if (y[0]=='libros'):
            return creacion_final3(x[1:],res+str(y[1]+'.'+y[2]+'.'+y[3]+'.'+y[4]+':'+x[5]+','+y[6]+".")+'\n')
        elif(y[0]=='Tesis'):
            return creacion_final3(x[1:],res+str(y[1]+'.'+y[2]+','+y[3]+','+y[4]+'.,'+y[5]+'.,'+y[6]+','+y[7]+','+y[8])+"."+'\n')
        elif(y[0]=='Periodicos'):
            return creacion_final3(x[1:],res+str(y[1]+'.'+y[2]+','+"¨"+y[3]+","+'¨'+y[4]+','+y[5]+","+'pp.'+","+y[6]+".,"+y[7]+".")+"\n")
        elif(y[0]=='Online'):
            return creacion_final3(x[1:],res+str(y[1]+','+y[2]+','+"("+y[3]+")"+','+"¨"+y[4]+"¨"+","+'Recuperado de '+y[5])+"\n")
        elif(y[0]=='Conferencias'):
            return creacion_final3(x[1:],res+str(y[1]+'.'+y[2]+','+"¨"+y[3]+","+'¨'+"Conf"+'.,'+y[4]+","+y[5]+","+'pp.'+y[6]+".")+"\n")
        else:
            return creacion_final3(x[1:],res)
    
#################################################################################################################################################################
        
#Filtro por Apellido
def buscando_Apellido(lista,autor):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],autor)):
            return lista[0]+buscando_Apellido(lista[1:],autor)
        
        else:
            return buscando_Apellido(lista[1:],autor)
#Filtro por Titulo
def buscando_Titulo(lista,titulo):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],titulo)):
            return lista[0]+buscando_Titulo(lista[1:],titulo)
        
        else:
            return buscando_Titulo(lista[1:],titulo)


#Filtro por Fecha
def buscando_Fecha(lista,Fecha):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],Fecha)):
            return lista[0]+buscando_Fecha(lista[1:],Fecha)
        
        else:
            return buscando_Fecha(lista[1:],Fecha)

#Filtro Apellido y Fecha
def buscando_AyF(lista,Fecha,Apellido):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],Fecha)and(pertenece(lista[0],Apellido))):
            return lista[0]+buscando_AyF(lista[1:],Fecha,Apellido)
        
        else:
            return buscando_AyF(lista[1:],Fecha,Apellido)        
#Filtro Apellido y Titulo
def buscando_AyT(lista,titulo,Apellido):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],titulo)and(pertenece(lista[0],Apellido))):
            return lista[0]+buscando_AyT(lista[1:],titulo,Apellido)
        
        else:
            return buscando_AyT(lista[1:],titulo,Apellido)
#Filtro Fecha y Titulo
def buscando_FyT(lista,titulo,Fecha):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],titulo)and(pertenece(lista[0],Fecha))):
            return lista[0]+buscando_FyT(lista[1:],titulo,Fecha)
        
        else:
            return buscando_FyT(lista[1:],titulo,Fecha)

#Todos los fitros
def buscando_AyTyF(lista,titulo,Apellido,Fecha):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],titulo)and(pertenece(lista[0],Apellido)and(pertenece(lista[0],Fecha)))):
            return lista[0]+buscando_AyTyF(lista[1:],titulo,Apellido,Fecha)
        
        else:
            return buscando_AyTyF(lista[1:],titulo,Apellido,Fecha)

def buscador_general(lista,general):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],general)):
            return lista[0]+buscador_general(lista[1:],general)
        
        else:
            return buscador_general(lista[1:],general)


#Pertence 
def pertenece(lista,inp):
    if(lista==[]):
        return False
    else:
        if(lista[0]==inp):
            return True
        else:
            return pertenece(lista[1:],inp)

############################################################Modo Consulta IEEE#####################################################################

def consulta_IEEE(ventana):
    def filtros():
        Apellido=entrada.get()
        titulo=entrada2.get()
        Fecha=entrada3.get()
        general=entrada4.get()
        lista=creacion_final4()
        print(lista)

        if(Apellido==''and(titulo!='')and(Fecha!='')):
            x=buscando_FyT2(lista,titulo,Fecha)
            y=creacion_final3(x,'')
            P=Label(vent9,text=y).grid(row=4,column=0)
            return P
        elif(titulo==''and(Apellido!='')and(Fecha!='')):
            x=buscando_AyF2(lista,Fecha,Apellido)
            y=creacion_final3(x,'')
            P=Label(vent9,text=y).grid(row=4,column=0)
            return P
        elif(Fecha==''and(Apellido!='')and(titulo!='')):
            x=buscando_AyT2(lista,titulo,Apellido)
            y=creacion_final3(x,'')
            P=Label(vent9,text=y).grid(row=4,column=0)
            return P
        elif(Apellido==''and(titulo=='')and(Fecha!='')):
            x=buscando_Fecha2(lista,Fecha)
            y=creacion_final3(x,'')
            P=Label(vent9,text=y).grid(row=4,column=0)
            return P
        elif(titulo!=''and(Apellido=='')and(Fecha=='')):
            x=buscando_Titulo2(lista,titulo)
            y=creacion_final3(x,'')
            P=Label(vent9,text=y).grid(row=4,column=0)
            return P
        elif(Fecha==''and(Apellido!='')and(titulo=='')):
            x=buscando_Apellido2(lista,Apellido)
            y=creacion_final3(x,'')
            P=Label(vent9,text=y).grid(row=4,column=0)
            return P
        
        elif(Fecha==''and(Apellido=='')and(titulo=='')and(general!="")):
            x=buscador_general2(lista,general)
            y=creacion_final3(x,'')
            P=Label(vent9,text=y).grid(row=11,column=0)
            return P
        
        elif(Fecha==''and(Apellido=='')and(titulo=='')):
            P=Label(vent9,text='Todo Vacio favor ingresar datos').grid(row=4,column=0)
            return P
        else:
            x=buscando_AyTyF(lista,titulo,Apellido,Fecha)
            y=creacion_final3(x,'')
            P=Label(vent9,text=y).grid(row=4,column=0)
            return P


    vent9=Toplevel(ventana)
    vent9.config()
    vent9.geometry("1000x500+0+0")
    vent9.title("Agregando Referencias")
    etiqueta=Label(vent9,text='Bienvenido al menu de busqueda llene los espacio que desea buscar',font=('Arial',14)).grid(row=0,column=2,sticky=W)
    etiqueta2=Label(vent9,text= 'Apellido del Autor:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta3=Label(vent9,text='Titulo de la pagina:',font=('Arial',14)).grid(row=2,column=0,sticky=W)
    etiqueta4=Label(vent9,text='Fecha:',font=('Arial',14)).grid(row=3,column=0,sticky=W)
    entrada=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    campo2=Entry(vent9,textvariable=entrada).grid(row=1,column=1,sticky=W)
    campo3=Entry(vent9,textvariable=entrada2).grid(row=2,column=1,sticky=W)
    campo4=Entry(vent9,textvariable=entrada3).grid(row=3,column=1,sticky=W)
    campo4=Entry(vent9,textvariable=entrada4).grid(row=10,column=1,sticky=W)
    boton= Button(vent9,text='Buscar',command=filtros).grid(row=5,column=0)
    boton2= Button(vent9,text='Buscador General',command=filtros).grid(row=10,column=0)

#Filtro por Apellido IEEE
#E:Una lista y una variable con el valor de un cuadro de texto
#S:Si en la lista esta el valor de la variable me imprime todos las sublistas donde aparece
def buscando_Apellido2(lista,autor):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],autor)):
            return lista[0]+list('   ') + buscando_Apellido2(lista[1:],autor)
        
        else:
            return buscando_Apellido2(lista[1:],autor)
#Filtro por Titulo IEEE
#E:Una lista y una variable con el valor de un cuadro de texto
#S:Si en la lista esta el valor de la variable me imprime todos las sublistas donde aparece
def buscando_Titulo2(lista,titulo):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],titulo)):
            return lista[0] +list('   ')+ buscando_Titulo2(lista[1:],titulo)
        
        else:
            return buscando_Titulo2(lista[1:],titulo)


#Filtro por Fecha IEEE
#E:Una lista y una variable con el valor de un cuadro de texto
#S:Si en la lista esta el valor de la variable me imprime todos las sublistas donde aparece       
def buscando_Fecha2(lista,Fecha):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],Fecha)):
            return lista[0] +list('   ')+ buscando_Fecha2(lista[1:],Fecha)
        
        else:
            return buscando_Fecha2(lista[1:],Fecha)

#Filtro Apellido y Fecha IEEE
#E:Una lista y una variable con el valor de un cuadro de texto
#S:Si en la lista esta el valor de la variable me imprime todos las sublistas donde aparece
def buscando_AyF2(lista,Fecha,Apellido):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],Fecha)and(pertenece(lista[0],Apellido))):
            return lista[0]+list('   ') + buscando_AyF2(lista[1:],Fecha,Apellido)
        
        else:
            return buscando_AyF2(lista[1:],Fecha,Apellido)        
#Filtro Apellido y Titulo IEEE
#E:Una lista y una variable con el valor de un cuadro de texto
#S:Si en la lista esta el valor de la variable me imprime todos las sublistas donde aparece
def buscando_AyT2(lista,titulo,Apellido):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],titulo)and(pertenece(lista[0],Apellido))):
            return lista[0] +list('   ')+ buscando_AyT2(lista[1:],titulo,Apellido)
        
        else:
            return buscando_AyT2(lista[1:],titulo,Apellido)
#Filtro Fecha y Titulo IEEE
#E:Una lista y una variable con el valor de un cuadro de texto
#S:Si en la lista esta el valor de la variable me imprime todos las sublistas donde aparece
def buscando_FyT2(lista,titulo,Fecha):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],titulo)and(pertenece(lista[0],Fecha))):
            return lista[0] +list('   ')+ buscando_FyT2(lista[1:],titulo,Fecha)
        
        else:
            return buscando_FyT2(lista[1:],titulo,Fecha)

#Todos los fitros IEEE
#E:Una lista y una variable con el valor de un cuadro de texto
#S:Si en la lista esta el valor de la variable me imprime todos las sublistas donde aparece
def buscando_AyTyF2(lista,titulo,Apellido,Fecha):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],titulo)and(pertenece(lista[0],Apellido)and(pertenece(lista[0],Fecha)))):
            return lista[0]+list('   ') + buscando_AyTyF2(lista[1:],titulo,Apellido,Fecha)
        
        else:
            return buscando_AyTyF2(lista[1:],titulo,Apellido,Fecha)
#Filtro busca en todas las posiciones todo lo que desee que esta en memoria
#E:Una lista y una variable con el valor de un cuadro de texto
#S:Si en la lista esta el valor de la variable me imprime todos las sublistas donde aparece
def buscador_general2(lista,general):
    if(lista==[]):
        return []
    else:
        if(pertenece(lista[0],general)):
            return lista[0]+buscador_general(lista[1:],general)
        
        else:
            return buscador_general(lista[1:],general)


##################################################################################################################################################################
#En esta codigo esta la ventana principal donde se comienza a llamar las siquientes ventanas hijas con su respectiva funcion

#Ventana Principal    
ventana=Tk()
ventana.config(bg="brown")
ventana.geometry("550x550+0+0")       #Damos el tamaño que deseamos de las ventanas
ventana.title("Referencia de Documentos")   #Damos el titulo de la ventana principal
##imagen0=PhotoImage(file="ima.gif")
##lblimagen=Label(vent1,image=imagen0)
##lblimagen.grid(row=2,column=3)
#Creacion de barra de menus
barra=Menu(ventana)
mnuMantenimiento=Menu(barra) #Creamos la pestaña mantenimiento en la barra
#Imagen
imagen0=PhotoImage(file="ima.gif")  #Podemos Colocar una imagen en la ventana principal y tiene que ser formato .gif
lblimagen=Label(ventana,image=imagen0)
lblimagen.grid(row=2,column=3) #Colocamos la imagen en la posicion deseada
#Crea las funciones de los menus
mnuConsulta=Menu(barra)   #Creamos la pestaña consulta en la barra
mnuMantenimiento.add_command(label="Ver Todas las Referencias de APA",command=lambda:ver(ventana))   #Construimos las acciones de la pestaña
mnuMantenimiento.add_command(label="Ver Todas las Referencias de IEEE",command=lambda:ver2(ventana))
mnuMantenimiento.add_command(label="Eliminar Referencias o Editar Referencias APA",command=lambda: eliminar(ventana))
mnuMantenimiento.add_command(label="Eliminar Referencias o Editar Referencias IEEE",command=lambda: eliminar2(ventana))
mnuMantenimiento.add_command(label="Agregar Referencias",command=lambda: agregar(ventana))
#mnuMantenimiento.add_command(label="Ver Referencias de forma individual",command=lambda: agregar(ventana))
mnuConsulta.add_command(label="Buscar Documentos APA",command=lambda: consulta(ventana))
mnuConsulta.add_command(label="Buscar Documentos IEEE",command=lambda: consulta_IEEE(ventana))
#ppp=Menu(mnuConsulta)
b1=Button(ventana,text="Salir",command=ventana.destroy)    #Creamos con destroy la la funcion salir en un boton
#Agrega los menus en la barra
barra.add_cascade(label="Mantenimiento",menu=mnuMantenimiento) #Invocamos el menu mantenimiento en la barra en la barra
barra.add_cascade(label="Consulta",menu=mnuConsulta)   #Invocamos el menu consulta en la barra
#mnuConsulta.add_cascade(menu=ppp)
b1.place(x='500',y='500') #Cargamos el boton en nuestra ventana
#Indicamos que la barra estra en la ventana
ventana.config(menu=barra)  #Invocamos en la ventana la barra de menus
ventana.mainloop() #funcion obligatoria para que corra la interfaz


