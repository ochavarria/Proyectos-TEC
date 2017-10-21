function [] = Menu_Inversa()
    disp('1)Metodo Gauss-Jordan');
    disp('2) Metodo Por matriz de cofactores');
    disp('3) Atras');
    
    x = input('- ');

    if (x==1)
        disp('1)Respuesta inmediata');
        disp('2) Paso a paso');
        disp('3) Menu');
        y = input('- ');
        if(y==1)
            a=input('Ingrese la matriz de forma "[fila;fila;fila..;fila-n]" ');
            Matriz=inv(a);
            disp(Matriz)
        end
        if(y==2)
            Inversafun();
        end 
        if(y>2)
            Menu();
        end
    end
    if (x==2)
        disp('1)Respuesta inmediata');
        disp('2) Paso a paso');
        disp('3) Menu');
        y = input('- ');
        if(y==1)
            a=input('Ingrese la matriz de forma "[fila;fila;fila..;fila-n]" ');
            Matriz=inv(a);
            disp(Matriz)
        end
        if(y==2)
            
            cofactor();
        end
        if(y>2)
            Menu();
        end
    end
    if (x>2)
        Menu();
    end
end