from Tkinter import *
def agregar():
    ventana=Tk()
    ventana.config()
    ventana.geometry("600x500+0+0")
    ventana.title("Agregando Referencias")
    etiqueta2=Label(ventana,text='Digite lo que se le solicita',font=('Times New Roman',14)).grid(row=0,column=3)
    etiqueta=Label(ventana,text='Titulo del libro:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta1= Label(ventana,text='Iniciales del autor:',font=('Arial',14),fg='black').grid(row=2,column=0,sticky=W)
    etiqueta3= Label(ventana,text='Apellido del autor:',font=('Arial',14),fg='black').grid(row=3,column=0,sticky=W)
    etiqueta4= Label(ventana,text='Cuidad de publicacion:',font=('Arial',14),fg='black').grid(row=4,column=0,sticky=W)
    etiqueta5= Label(ventana,text='Nombre de la editorial:',font=('Arial',14),fg='black').grid(row=5,column=0,sticky=W)
    # Creando un campo de texto
    #set es para asignarle algo al campo
    entrada=StringVar()
    entrada1=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    entrada5=StringVar()
    Campo=Entry(ventana,textvariable=entrada).grid(row=1,column=1)
    Campo2=Entry(ventana,textvariable=entrada2).grid(row=2,column=1)
    campo3=Entry(ventana,textvariable=entrada3).grid(row=3,column=1)
    campo4=Entry(ventana,textvariable=entrada4).grid(row=4,column=1)
    campo5=Entry(ventana,textvariable=entrada5).grid(row=5,column=1)
    ventana.mainloop()
def agregar2():
    ventana=Tk()
    ventana.config()
    ventana.geometry("600x500+0+0")
    ventana.title("Agregando Referencias")
    etiqueta=Label(ventana,text='Apellido del Autor:',font=('Arial',14)).grid(row=0,column=0,sticky=W)
    etiqueta2=Label(ventana,text='Iniciales del Autor:',font=('Arial',14)).grid(row=1,column=0,sticky=W)
    etiqueta3=Label(ventana,text='Titulo de la tesis:',font=('Arial',14)).grid(row=2,column=0,sticky=W)
    etiqueta4=Label(ventana,text='Tesis de (Grado academico) no publicada:',font=('Arial',14)).grid(row=3,column=0,sticky=W)
    etiqueta5=Label(ventana,text='Nombre de la Universidad',font=('Arial',14)).grid(row=4,column=0,sticky=W)
    etiqueta6=Label(ventana,text='Cuidad de la publicacion:',font=('Arial',14)).grid(row=5,column=0,sticky=W)
    etiqueta7=Label(ventana,text='Pais de la publicacion:',font=('Arial',14)).grid(row=6,column=0,sticky=W)
    entrada=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    entrada4=StringVar()
    entrada5=StringVar()
    entrada6=StringVar()
    entrada7=StringVar()
    Campo=Entry(ventana,textvariable=entrada).grid(row=0,column=1)
    Campo2=Entry(ventana,textvariable=entrada2).grid(row=1,column=1)
    campo3=Entry(ventana,textvariable=entrada3).grid(row=2,column=1)
    campo4=Entry(ventana,textvariable=entrada4).grid(row=3,column=1)
    campo5=Entry(ventana,textvariable=entrada5).grid(row=4,column=1)
    campo6=Entry(ventana,textvariable=entrada6).grid(row=5,column=1)
    campo7=Entry(ventana,textvariable=entrada7).grid(row=6,column=1)
    ventana.mainloop()
def ejecutar(funcion):
	ventana.after(200,funcion)
def abrir(ventanasecundaria):
	ventanasecundaria.deiconify()
def cerrar(ventanasecundaria):
	ventanasecundaria.withdraw()
def agregar1():
    ventana = Tk()
    ventana.config()
    ventana.geometry("600x400")
    texto = Label(ventana,text="Elija que tipo de referencia desea agregar")
    texto.grid(row=0,column=1)
    boton = Button(ventana,text="Referencia de libros",command=lambda : ejecutar(agregar()))
    boton.grid(row=1,column=0)
    boton2=Button(ventana,text="Referencia de tesis",command=lambda : ejecutar(agregar2()))
    boton2.grid(row=2,column=0)
    ventana.mainloop()

def eliminar():
    vent2=Tk()
    vent2.config(bg="blue")
    vent2.geometry("400x200+0+0")
    vent2.title("Eliminando Referencias")
    vent2.mainloop()

def ver():
    vent2=Tk()
    vent2.config(bg="blue")
    vent2.geometry("400x200+0+0")
    vent2.title("Mostrando Referencias en Memoria")
    vent2.mainloop()

def APA():
    vent2=Tk()
    vent2.config(bg="blue")
    vent2.geometry("400x200+0+0")
    vent2.title("APA")
    vent2.mainloop()

def IEEE():
    vent2=Tk()
    vent2.config(bg="blue")
    vent2.geometry("400x200+0+0")
    vent2.title("IEEE")
    vent2.mainloop()
##################################################################
def principal():
    #Construimos una ventana    
    vent1=Tk()
    vent1.config(bg="brown")
    vent1.geometry("550x550+0+0")       #Damos el tamaño que deseamos de las ventanas
    vent1.title("Referencia de Documentos")   #Damos el titulo de la ventana principal
    #Creacion de barra de menus
    barra=Menu(vent1)
    mnuMantenimiento=Menu(barra) #Creamos la pestaña mantenimiento en la barra
    #Crea las funciones de los menus
    mnuConsulta=Menu(barra)   #Creamos la pestaña consulta en la barra
    mnuMantenimiento.add_command(label="Ver Referencias",command=ver)   #Construimos las acciones de la pestaña
    mnuMantenimiento.add_command(label="Eliminar Referencias",command=eliminar)
    mnuMantenimiento.add_command(label="Agregar Referencias",command=agregar1)
    mnuConsulta.add_command(label="Buscar Documentos APA",command=APA)
    mnuConsulta.add_command(label="Buscar Documentos IEEE",command=IEEE)
    b1=Button(vent1,text="Salir",command=vent1.destroy)    #Creamos con destroy la la funcion salir en un boton
    #Agrega los menus en la barra
    barra.add_cascade(label="Mantenimiento",menu=mnuMantenimiento) #Invocamos el menu mantenimiento en la barra en la barra
    barra.add_cascade(label="Consulta",menu=mnuConsulta)   #Invocamos el menu consulta en la barra
    b1.place(x='500',y='500') #Cargamos el boton en nuestra ventana
    #Indicamos que la barra estra en la ventana
    vent1.config(menu=barra)  #Invocamos en la ventana la barra de menus
    vent1.mainloop() #funcion obligatoria para que corra la interfaz
principal()



