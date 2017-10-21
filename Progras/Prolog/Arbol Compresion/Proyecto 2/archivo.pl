%Librerias para trabajar
:- use_module(library(pio)).
:- use_module(library(lists)).
:- use_module(library(pairs)).

%abrir:-
%	working_directory(CWD,'/Users/DXNNX/Desktop/prolog').
%	consult('archivo.pl').


crearDiccionario(File) :- %Para iniciar la creacion del diccionario
    open(File, read, Str),
    leerLineas(Str,Lines),%Lee las lineas
	atomic_list_concat(Lines, '\n', AllStr),%Las encadena eliminando
	line_count(Str, LinesCounter),%Cuenta las lineas
    close(Str),%Cierra el Stream
    splitEspacio(Lines,[], LinesCounter,AllStr,File).%Hace lista con division de espacios (Para sacar palabras)


tuplas_ocurrencias(List,LC, Occ, AllStr,File):- %Cuenta las ocurrencias
    findall([L,X], (bagof(true,member(X,List),Xs),length(Xs,L)), Occ), %Crea lista de ocurrencias
	append(Occ,[[LC,'\\n']],Occ2),%Modificacion para el breakline
	atom_codes(AllStr, L2),
	count(32,L2,Y),%Cuenta el caracter 32 (Espacio)
	append(Occ2,[[Y,' ']],Occ3),%Lo agrega al final
    dict(Occ3,File).%Continua el proceso

%Empieza un ordenamiento burbuja en prolog
bubble_sort(List,Sorted):-b_sort(List,[],Sorted).
b_sort([],Acc,Acc).
b_sort([H|T],Acc,Sorted):-bubble(H,T,NT,Max),b_sort(NT,[Max|Acc],Sorted).

bubble(X,[],[],X).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%Lineas de adaptacion 
%%Si la linea es blanca (Espacio) la
%%Excluye de el ordenamiento
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bubble(X,[Y|T],[Y|NT],Max):-nth0(1,X,A),A='',bubble(Y,T,NT,Max).
bubble(X,[Y|T],[Y|NT],Max):-nth0(1,Y,B),B='',bubble(X,T,NT,Max).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Ordenamiento de posiciones ceros de las tuplas [Contador,Elemento]
bubble(X,[Y|T],[Y|NT],Max):-nth0(0,X,A),nth0(0,Y,B),A>B,bubble(X,T,NT,Max).
bubble(X,[Y|T],[X|NT],Max):-nth0(0,X,A),nth0(0,Y,B),A=<B,bubble(Y,T,NT,Max).


dict(Y,_):- %Generador diccionario
		bubble_sort(Y,Y2), %Ordenamiento
		reverse(Y2,Y11),%Inversor de lista
		open('./diccionario.txt', write, Str), %Abre archivo Diccionario
		escribirArchivo(Y11,Str),%Escribe diccionario
		close(Str).%Cierra Stream



genArbol([[V1|R1], [V2|R2]|T], AF) :- %Genera una lista con la formula [Contador,[ValorArbol1,ValorArbol2]]
	V is V1 + V2, %Suma de ambos arboles V1/V2 es el valor de los arboles y R1/R2 es el resto del arbol
	A = [V, [V1|R1], [V2|R2]], %A = Valor, Arbol1,Arbol2
	(   T=[] -> AF=A ;  sort([A|T], NT), genArbol(NT, AF) ). %Se continua con la siguiente recursion

codigo([_A,FG,FD], Code, CF) :- %Genera el codigo
	(   nodo(FG) ->  codigo(FG, [0 | Code], C1) %Hace recursivamente hasta llegar al nodo, para poder agregarlo al arbol y creando el predicado
			 ;  codigoHoja(FG, [0 | Code], C1) ),
	(   nodo(FD) ->  codigo(FD, [1 | Code], C2)
			 ;  codigoHoja(FD, [1 | Code], C2) ),
	append(C1, C2, CF).

codigoHoja([FG,FD], Code, CF) :- %Crear hojas
	reverse(Code, CodeR),
	CF = [[FG, FD, CodeR]].

nodo([_V, _FG, _FD]). %Define el hecho nodo

splitEspacio([C|R],Y, LC,AllStr,File):- atomic_list_concat(T,' ', C), append(T,Y,Z),splitEspacio(R,Z,LC,AllStr,File).%Divide las lineas por espacios
splitEspacio([],Y,LC,AllStr,File):- tuplas_ocurrencias(Y, LC,_Ys,AllStr,File). %Sigue con las ocurrencias

leerLineas(File, [L|Lines]) :-
    read_line_to_codes(File, Codes), Codes \= end_of_file,
    atom_codes(L, Codes),
    L \= stop,
    !, leerLineas(File, Lines).
leerLineas(_, []).


count(W, L, N) :-
    aggregate(count, member(W, L), N).

escribirArchivo([],_).
escribirArchivo([[H,C]|T],Stream):- write(Stream,C),write(Stream,': '),write(Stream,H),write(Stream,'\n'),escribirArchivo(T,Stream).


comprimirTexto(X):- %Inicia proceso de comprimir texto
    open('./diccionario.txt', read, Str),
    leerLineas(Str,Lines),
    close(Str),
    open(X, read, Str2),
    leerLineas(Str2,Line),
	atomic_list_concat(Line, '\n', AllStr),
    close(Str2),
	cargarDiccionario(Lines,[],AllStr). %Comienza leyendo el diccionario 

crearArbolCompresion(Lista,AllStr):- %Continua el proceso
	genArbol(Lista,L),%Genera arbol con estructura
	codigo(L,[],Y4),
	sort(Y4,Y5),
	atomic_list_concat(L2, ' ', AllStr),
	remplazarResto(L2,Y5,Y5).


cargarDiccionario([],A,AllStr):- crearArbolCompresion(A,AllStr). %Recrea arbol
cargarDiccionario([C|T],A,AllStr):- %Lee las lineas del diccionario.txt y recrea el arbol
	atomic_list_concat(L, ': ', C),
	nth0(0,L,B),
	nth0(1,L,Z),
	atom_number(Z,Z2),
	remplazarPalabra('\\n','\n',B,D),
	cargarDiccionario(T,[[Z2,D]|A],AllStr). %Carga diccionario
	
remplazarPalabra(Old, New, Orig, Replaced) :- %Remplaza una palabra en un string y la regresa
    atomic_list_concat(Split, Old, Orig), 
    atomic_list_concat(Split, New, Replaced). 


remplazarResto(AllStr,[[_,Y,Z]|T],Dict):- %Remplaza las palabras, concatena el codigo y los caracteres "shift+3" (Mac Os X Latin Layout) y lo reemplaza en el texto original
	atomic_list_concat(Z, '', Codigo),
    string_concat(Codigo, '·', Codigo3),
	string_concat('·',Codigo3, Codigo2),
	replace(Y,Codigo2,AllStr,AllStr2),
	remplazarResto(AllStr2,T,Dict).
	
remplazarResto(Compressed,[],Dict):-
    buscarEspacio(' ',Dict,Compressed,Dict). %Procede a reemplazar espacios 

replace(_, _, [], []).
replace(O, R, [O|T], [R|T2]) :- replace(O, R, T, T2).
replace(O, R, [H|T], [H|T2]) :- H \= O, replace(O, R, T, T2).


buscarEspacio(_,[],A,D):- %Los une y procede a reemplazar los saltos de linea
	atomic_list_concat(A, '', AllStr2),
	atomic_list_concat(T,'\n', AllStr2),
	buscarNl('\n',D,T).

buscarEspacio(X,[[_,X,Z]|_],AllStr,Dict):- %Concatena los espacios, dividiendo los otros codigos
	atomic_list_concat(Z, '', Codigo),
    string_concat(Codigo, '·', Codigo3),
	string_concat('·',Codigo3, Codigo2),
	atomic_list_concat(AllStr, Codigo2, AllStr2),
	atomic_list_concat(T,'\n', AllStr2),
	buscarNl('\n',Dict,T,Dict). %Procede a reemplazar los saltos de linea
buscarEspacio(X,[[_,_,_]|Tail],AllStr,Dict) :- 	buscarEspacio(X,Tail,AllStr,Dict).

buscarNl(_,[],AllStr,Di):- %Reemplaza los saltos de linea y Procede a reeleer los coodigos, dado que los saltos de linea generan problemas al reemplazar
	atomic_list_concat(AllStr, '', AllStr2),
	atomic_list_concat(AllStr3, '·',AllStr2),
	remplazarResto2(AllStr3,Di).

buscarNl(X,[[_,X,Z]|_],AllStr,Di):-
	atomic_list_concat(Z, '', Codigo),
    string_concat(Codigo, '·', Codigo3),
	string_concat('·',Codigo3, Codigo2),
	atomic_list_concat(AllStr, Codigo2, AllStr2),
	atomic_list_concat(AllStr3, '·',AllStr2),
	remplazarResto2(AllStr3,Di,Di).

buscarNl(X,[[_,_Y,_Z]|Tail],AllStr,Di):- buscarNl(X,Tail,AllStr,Di).

remplazarResto2(AllStr,[[_,Y,Z]|T],Dict):- %Vuelve a intentar reemplazar, sin los saltos de linea ahora si pueden ser reemplazados
	atomic_list_concat(Z, '', Codigo),
    string_concat(Codigo, '·', Codigo3),
	string_concat('·',Codigo3, Codigo2),
	replace(Y,Codigo2,AllStr,AllStr2),
	remplazarResto2(AllStr2,T,Dict).
	
remplazarResto2(Compressed,[],_):-
	atomic_list_concat(Compressed, '·', AllStr),
    finalCompresion(AllStr).


finalCompresion(Compressed):-  %Crea el comprimido 
    open('./comprimido.txt', write, Str),
    write(Str,Compressed),
    close(Str).


descomprimir:- %Inicia proceso de descomprimir texto, carga el diccionario y el archivo comprimido
	open('./diccionario.txt', read, Str),
	leerLineas(Str,Lines),
	close(Str),
	open('./comprimido.txt', read, Str2),
	leerLineas(Str2,Line),
	atomic_list_concat(Line, '\n', AllStr),
	close(Str2),
	cargarDiccionarioD(Lines,[],AllStr).

crearArbolCompresionD(Lista,AllStr):- %Carga el diccionario creado anteriormente
	genArbol(Lista,L),
	codigo(L,[],Y4),
	sort(Y4,Y5),
	atomic_list_concat(L2, '·', AllStr),
	remplazarResto(L2,Y5).

cargarDiccionarioD([],A,AllStr):- crearArbolCompresionD(A,AllStr).
cargarDiccionarioD([C|T],A,AllStr):-
	atomic_list_concat(L, ': ', C),
	nth0(0,L,B),
	nth0(1,L,Z),
	atom_number(Z,Z2),
	remplazarPalabra('\\n','\n',B,D),
	cargarDiccionarioD(T,[[Z2,D]|A],AllStr).

remplazarResto(AllStr,[[_,Y,Z]|T]):- %Reemplaza el codigo por el texto
	atomic_list_concat(Z, '', Codigo),
	replace(Codigo,Y,AllStr,AllStr2),
	remplazarResto(AllStr2,T).
	
remplazarResto(Compressed,[]):- atomic_list_concat(Compressed, '', C), 
	open('./descomprimido.txt', write, Str), %Genera nuevo documento con el texto comprimido
    write(Str,C),
    close(Str).