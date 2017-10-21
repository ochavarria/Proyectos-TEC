import ast
from Tkinter import *
from tkFileDialog import askopenfilename
import winsound
#############################################################################################################################################################
#La funcion que abre y carga el archivo
#E:
#S:El archivo seleccionado cargado
#R:El achivo seleccionado tiene que ser un .txt

def cargar(vent):
    Tk().withdraw() 
    filename = askopenfilename() 

    x = open(filename,'r')
    x=x.read()
    if x!='':
        
        grid = ast.literal_eval(x)
        

############################################################################################################################################################
        global M
        M=grid
        global pasos
        pasos=[]
        global buttons
        buttons = []
        global valor
        valor=1

###########################################################################################################################################################
        Lab = Laberinto(grid)

        global w
        w=encontrar1(0,0)
        if w!=[]:
            global t
            t=encontrar2(0,0)
            if t!=[]:
                Lab.backtracking(w[0],w[1])

                global solucion
                solucion=listacamino(grid,0,0,[])
            else:
                return Label(vent,text='El laberinto no tiene salida',bg="Black",relief=FLAT,fg='magenta').place(x=20,y=100)
                
        else:
            return Label(vent,text='El laberinto no tiene entrada',bg="Black",relief=FLAT,fg='magenta').place(x=20,y=100)
        
    else:
        return Label(vent,text='El laberinto no existe',bg="Black",relief=FLAT,fg='magenta').place(x=20,y=100)
###########################################################################################################################################################

#La funcion que da el acerca de 
#E:ventana 
#S:La informacion sobre el juego 
#R:
def info(vent):
    vent1=Toplevel(vent)
    
    x='''Acerca de laberinto:\n
    Este programa como su nombre lo dice es un laberinto, el cual tienes que solucionar.\n
    Ventajas:\n
    una ventaja es que podras crear tu propio laberinto\n
    Incluye:\n
    Este programa tiene la opcion de jugar, solucion y ayuda en caso que no entiendas algo\n
    Requisitos de laberinto\n
    Para poder jugar necesitas el leguaje de python version 2.7 o mayor\n
    Notas acerca de los derechos de autor:\n
    Este programa fue desarollado por Oscar Chavarria.Este software puede utilizarse para jugar.\n 
    La licencia por la cual se le concede le permite utilizarlo únicamente para jugar.\n
    Si tiene alguna duda acerca de los derechos del juego\n
    Pongase en contacto con el creador del juego, Oscar Chavarria  correo: ocach14@hotmail.com.'''

    return Label(vent1,text=x).grid(row=0,column=0)

def ayuda(vent):
    vent1=Toplevel(vent)
    
    x='''Como Jugar:\n
        1-Primero debes abrir una matriz, y para eso vamos a la barra
         de herramientas y damos click a cargar Laberinto.\n
        2-Con el laberinto cargado estamos listos para jugar
         Para empezar a jugar damos click en jugar en la barra de
         de herramientas\n
        3-Al darle click te abrira otra ventana con el laberinto.
         Para jugar solo debes darle click por donde quieras ir 
         pasando.\n
        4-Una vez llegado a la meta final, te aparecera un cuadro
         en donde se te pregunta si deseas volver a jugar.\n
         Exepciones:
        1-Si no abres el laberinto primero antes de darle
         click a jugar no se abrira nada.\n
        2-Si el laberinto es menor que 8x8 o mayor que 25x25
         no se te abrira el juego.\n
        3-No podras clickear un lugar sin antes haberlo activado
         y para activar el boton tendras que activar un bonton
         anterior a este a exepcion del primero.\n

         Espero que hayas entendido y a jugar se ha dicho!!'''

    return Label(vent1,text=x).grid(row=0,column=0,sticky=NW)


############################################################################################################################################################
# Esta funcion es la que coge el camino que lleva a la salida en la matriz 


#E: El laberinto, los indices (x,y), y una lista 
#S:
#R:Tiene que ser una matriz el laberinto,, x y y integers y lista una lista 
def listacamino(mazeList,x,y,lista):
    if x==len(mazeList):
        return lista
    else:
        if y==len(mazeList[0]):
            return listacamino(mazeList,x+1,0,lista)
        else:
            if mazeList[x][y]==3:
                return listacamino(mazeList,x,y+1,lista+[[x,y]])
            else:
                return listacamino(mazeList,x,y+1,lista)




# Esta funcion es la que resuelve el laberinto
                
#E:Una matriz
#S: La matriz resuelta
#R:Tiene que ser una matiz 
class Laberinto:
    def __init__(self, M):
        self.M = M

    def backtracking(self,x,y):
        M = self.M
 
 
        if x >= len(M) or y >= len(M[0]):
            return False
 
        if M[x][y] == 2:
            return True
 
        if  M[x][y] not in (0, -1):
            return False
 

        M[x][y] = 3      
 

        if self.backtracking(x+1, y) == True :  #right
            M[x][y] = 3      
            return True
       
        if self.backtracking(x, y+1) == True :  #down
            M[x][y] = 3      
            return True
       
        if self.backtracking(x-1, y) == True :  #left
            M[x][y] = 3     
            return True
       
        if self.backtracking(x, y-1) == True :  #up
            M[x][y] = 3      
            return True  
 
        #Backtracking
        M[x][y] = 0
        return False



#################################################################################################################################################################
#ESta funcion cambia de color a los botones 
#E:una lista ,un contador, dos indices y un integer 
#S:El boton cambiando de color 
#R:Tiene que ser una lista y los indices integers 
def color(buttons,cont,w,z,valor):
    if valor%2==0:
        if buttons[cont].x==w and buttons[cont].y==z:
            buttons[cont].button['bg']='navy'
            return  
        else:
            return color(buttons,cont+1,w,z,valor)
    else:
        if buttons[cont].x==w and buttons[cont].y==z:
            buttons[cont].button['bg']='dark orchid'
            return  
        else:
            return color(buttons,cont+1,w,z,valor)



#############################################################################################################################################################
# Esta funcion encuentra la entrada del laberinto 
#E:dos indices 
#S:Donde se encuentra el -1 en la matriz 
#R:Tienen que ser integers los indices 
def encontrar1(x,y):
    if x==len(M):
        return []
    elif y==len(M[0]):
        return encontrar1(x+1,0)
    elif M[x][y]==-1:
        return [x,y]
    else:
        return encontrar1(x,y+1)



############################################################################################################################################################
# Esta funcion encuentra la salida del laberinto 
#E:dos indices 
#S:Donde se encuentra el 2 en la matriz 
#R:Tienen que ser integers los indices 
def encontrar2(x,y):
    if x==len(M):
        return []
    elif y==len(M[0]):
        return encontrar2(x+1,0)
    elif M[x][y]==2:
        return [x,y]
    else:
        return encontrar2(x,y+1)        


#################################################################################################################################################################
#Esta funcion cuenta las veces que el usuario apreta un boton(los pasos)
#E:Una lista y la ventana 
#S:la cantidad de pasos que ha hecho 
#R:Tiene que ser una lista
def contador(pasos,ventana):
    pasos.append([1])
    texto=Label(ventana,text='Pasos= '+str(len(pasos)//2), bg='dark orchid', fg='black').grid(row=26,column=27)

#############################################################################################################################################################

#Esta funcion muestra un mensaje a la hora de haber ganado 
#E:una ventana
#S:Un mensaje
#R:
def ganar(ventana):
    import tkMessageBox
    mensaje=tkMessageBox.askyesno(title="Felicitaciones", message="Has Resuelto el laberinto!\n Deseas volver a jugar?")
    if mensaje>0:
        return jugar(ventana)
#################################################################################################################################################################

#Esta funcion llama a otras funciones 
#E:dos indices, dos listas y una ventana
#S:Varias funciones 
#R:Tiene que ser integers los indices, las listas listas
def multifuncion(x,y,pasos,ventana):
    global valor
    valor=valor+1
    color(buttons,0,x,y,valor)
    contador(pasos,ventana)
    appear(x,y)



#################################################################################################################################################################
#Esta funcion me activa los siguientes botones despues de haber apretado uno 
#E:dos indices 
#S:Los botones activados
#R:Los indices tienen que ser integers 
def appear(w,z):
    cont=recorrer(buttons,0,w,z,[])
    if len(cont)!=0:
        if len (cont)==1:
            buttons[cont[0]].button['state']='active'
        elif len(cont)==2:
            buttons[cont[0]].button['state']='active'
            buttons[cont[1]].button['state']='active'
        elif len(cont)==3:
            buttons[cont[0]].button['state']='active'
            buttons[cont[1]].button['state']='active'
            buttons[cont[2]].button['state']='active'




#############################################################################################################################################################
#Esta funcion crea botones como objetos
#E: dos integers, dos listas, una ventana  
#S:Los botones como objetos 
#R:Tiene que ser integers y listas
class Crear():
    def _init_(self):
        return ''
    def boton(self,x,y,ventana,w,t):
        if x== w[0] and y==w[1]:                
            self.x=x
            self.y=y
            self.button = Button(ventana,text='inicio',bg='Dark Orchid',width=5,relief=FLAT, height=1,state='active',command=lambda:multifuncion(x,y,pasos,ventana))
            self.button.grid(row=x,column=y)
        elif x== t[0] and y==t[1]:
            self.x=x
            self.y=y
            self.button = Button(ventana,text='fin',bg='Dark Orchid',fg='black',width=5,relief=FLAT, height=1,state='disable',command=lambda:ganar(ventana))
            self.button.grid(row=x,column=y)
        else:          
            self.x=x
            self.y=y
            self.button = Button(ventana,width=5,relief=FLAT,bg='Dark Orchid', height=1,state='disable',command=lambda:multifuncion(x,y,pasos,ventana))
            self.button.grid(row=x,column=y)


    
#############################################################################################################################################################
#Esta funcion da una lista con las posiciones en las que los botones se tiene que activar 
# un contador dos integers y dos lista 
#S:una lista con las posiciones de los botones que encontro 
#R:Tiene que ser listas de objetos, y integers 
def recorrer(buttons,cont,w,z,res):
    if cont== len(buttons):
        return res
    else:            
        if buttons[cont].x==w and buttons[cont].y==z+1:
            return recorrer(buttons,cont+1,w,z,res+[cont])

        elif buttons[cont].x==w+1 and buttons[cont].y==z:
            return recorrer(buttons,cont+1,w,z,res+[cont])

        elif buttons[cont].x==w and buttons[cont].y==z-1:
            return recorrer(buttons,cont+1,w,z,res+[cont])

        elif buttons[cont].x==w-1 and buttons[cont].y==z:
            return recorrer(buttons,cont+1,w,z,res+[cont])

        else:
            return recorrer(buttons,cont+1,w,z,res)
        



#############################################################################################################################################################
#Esta funcion construye los botones 
#E:una matriz dos integers una ventana, dos listas 
#S:Los botonos creados y puestos en la ventana
#R:Tiene que ser integers y listas 
def construir(M,x,y,m,n,ventana,w,t):

    if x==m:
        return''
    else: 

        if y==n:
            return construir(M,x+1,0,m,n,ventana,w,t)

        else:

            if M[x][y]==0 or M[x][y]==3 :
                bot=Crear()
                bot.boton(x,y,ventana,w,t)
                buttons.append(bot)
 
                return construir(M,x,y+1,m,n,ventana,w,t)

            elif M[x][y]==1:
                Label(ventana,bg='grey8',width=5, height=1,relief=RAISED).grid(row=x,column=y)
                return construir(M,x,y+1,m,n,ventana,w,t)


            elif M[x][y]==-1:
                bot=Crear()
                bot.boton(x,y,ventana,w,t)
                buttons.append(bot)


                return construir(M,x,y+1,m,n,ventana,w,t)
            else:
                bot=Crear()
                bot.boton(x,y,ventana,w,t)
                buttons.append(bot)

                return construir(M,x,y+1,m,n,ventana,w,t)

#############################################################################################################################################################
#Esta funcion construye la ventana con los botones 
#E:una ventana 
#S:Una ventana 
#R:Tiene que ser una ventana
def jugar(vent):
    if M== '':
        return Label(vent,text='Debes  Abrir el laberinto primero, si necesitas ayuda Tenemos\nLa opcion de acerca donde se explica como funciona el juego',bg="Black",relief=FLAT,fg='magenta').place(x=0,y=0)
    else:

#############################################################################################################################################################
#Esta funcion determina de que deficultad es el laberinto
#E:
#S:Un label con la dificultad del laberinto 
#R:
        def niveles():
            if len(M)<8 or len(M[0])<8:
                Label(vent,text='El laberinto tiene que ser 8x8 o mas',bg="Black",relief=FLAT,fg='magenta').place(x=20,y=100)
                ventana.destroy()
                return ventana.destroy()
            elif len(M)>26 or len(M[0])>26:
                Label(vent,text='El laberinto tiene que ser 26x26 o menos',bg="Black",relief=FLAT,fg='magenta').place(x=20,y=100)
                ventana.destroy()
                return ventana.destroy()
            
            elif 8<=len(M)<11 and 8<=len(M[0])<11:
                return Label(ventana,text='Dificultad:facil', bg='dark orchid', fg='black').grid(row=0,column=26)
                
            elif 11<=len(M)<14 and 11<=len(M[0])<14:
                return Label(ventana,text='Dificultad:normal', bg='dark orchid', fg='black').grid(row=0,column=26)

            elif 14<=len(M)<26 and 14<=len(M[0])<26:
                return Label(ventana,text='Dificultad:dificil', bg='dark orchid', fg='black').grid(row=0,column=26)

            elif 14<=len(M)<26 or 14<=len(M[0])<26:
                return Label(ventana,text='Dificultad:dificil', bg='dark orchid', fg='black').grid(row=0,column=26)

            elif 11<=len(M)<14 or 11<=len(M[0])<14:
                return Label(ventana,text='Dificultad:normal', bg='dark orchid', fg='black').grid(row=0,column=26)

            elif 8<=len(M)<11 or 8<=len(M[0])<11:
                return Label(ventana,text='Dificultad:facil', bg='dark orchid', fg='black').grid(row=0,column=26)



#################################################################################################################################################################
#Esta funcion printea solucion del laberinto 
#E:una lista 
#S:La solucion de la matriz puesta en la ventana
#R:Tiene que ser una lista
        def solve(solucion):
            if solucion==[]:
                return ''
            else:
                o=solucion[0][0]
                s=solucion[0][1]
                Button(ventana,bg="green", width=5, height=1,relief=FLAT).grid(row=o,column=s)
                return solve(solucion[1:]) 
                        

#################################################################################################################################################################

                    #Construimos una ventana    
        ventana=Toplevel(vent)
        ventana.geometry("550x550+0+0")       #Damos el tamaÃ±o que deseamos de las ventanas
        ventana.title("Laberinto")   #Damos el titulo de la ventana principal
        ventana.config(bg='black')

        niveles()

        construir(M,0,0,len(M),len(M[0]),ventana,w,t)
        
        Button(ventana,text='solucion',width=5,height=1,bg='Dark Orchid',command=lambda:solve(solucion)).grid(row=26,column=26)   


#################################################################################################################################################################
#E:
#S:Una ventana
#R:
def principal():
    #Construimos una ventana    
    vent=Tk()
    vent.config(bg="Black")
    vent.geometry("625x540")       #Damos el tamaÃ±o que deseamos de las ventanas
    vent.title("Laberinto")   #Damos el titulo de la ventana principal

    imagen0=PhotoImage(file="maze.gif")  #Podemos Colocar una imagen en la ventana principal y tiene que ser formato .gif
    lblimagen=Label(vent,image=imagen0)
    lblimagen.grid(row=2,column=3) #Colocamos la imagen en la posicion deseada

    
    winsound.PlaySound("crazy.wav",winsound.SND_ASYNC)



    #Creacion de barra de menus
    barra=Menu(vent)
    #Crea las funciones de los menus
    mnuConsulta=Menu(barra)   #Creamos la pestaÃ±a consulta en la barra
    mnuConsulta.add_command(label="Jugar",command=lambda: jugar(vent))
    mnuConsulta.add_command(label="Cargar Laberinto",command=lambda: cargar(vent))
    mnuConsulta.add_command(label="Ayuda",command=lambda: ayuda(vent))
    mnuConsulta.add_command(label="Acerca de",command=lambda: info(vent))
    mnuConsulta.add_command(label="Salir",command=lambda: vent.destroy())
    barra.add_cascade(label="Juego",menu=mnuConsulta)   #Invocamos el menu consulta en la barra\




    #Label
    label=Label(vent,text='Bienvenido Al laberinto Mistico',bg="Black",relief=FLAT,fg='magenta')
    label.place(x=310,y=100)
    #Indicamos que la barra estra en la ventana
    vent.config(menu=barra)  #Invocamos en la ventana la barra de menus
    vent.mainloop() #funcion obligatoria para que corra la interfaza
principal()
