import scala.collection.mutable.Queue;
//Largo de la matriz
var largo = 3;
//Heuristica a utiliza
var HeuristicaSeleccionada = 0;
//Numeros de inicio
var NumDefault = List[Int]();
//Meta de la matriz
var CustomMeta = List[Int]();
//Set a variables globales
object Main{
	def main(args: Array[String]){
		if(args.size>0){largo=args(0).toInt;}
		if(args.size>1){HeuristicaSeleccionada=args(1).toInt;}
		if(args.size>2){
			if(args(2).size!=0){
			NumDefault=((args(2).split(" ").toList).map(_.toInt)).toList;
			
			if(NumDefault.size != largo*largo || (args.size<4 && !Estaticos.Solucionable(NumDefault))){println("El largo no es el correcto o la matriz no es solucionable");return;}}else{NumDefault = Estaticos.IniciarNumeros(largo).toList;}}else{NumDefault = Estaticos.IniciarNumeros(largo).toList;}
		if(args.size>3){CustomMeta=((args(3).split(" ").toList).map(_.toInt)).toList;}else{CustomMeta = ((1 to (largo*largo)-1).toList)++List(0)}
		var Puzzle = new Armar().Iniciar();
	  }
}
//La clase estado tiene los datos de un tablero 
class Estado(var Puzzle:Array[Int], var Cero:Int, var g:Double, var h:Double, var Padre:Estado) {
	//Constructor para la matriz de inicio
	def this(Mapa:Array[Int]){
		this(Mapa,-1,0,-1,null);
		 Cero = getCero(Mapa);
		 Padre = null;
		 g = 0;
		 h = getHeuristica();
	}
	//Selecciona la heuristica
		def getHeuristica():Double ={if(HeuristicaSeleccionada == 0){return getHeuristicaE(Puzzle);};if(HeuristicaSeleccionada == 1){return getHeuristicaJ(Puzzle);};return getHeuristicaM(Puzzle);}
	//Constructor para un nodo hijo, guardado el padre y la posicion donde se encuentra el cero
	def this(Nuevo:Array[Int],Superior:Estado,Space:Int){
		this(Nuevo,Space,Superior.getF()+1,0,Superior);
		h = getHeuristica();
	}
	//Heuristica de Manhattan, cuanta los cuadros de distancia entre el elemento y la posicion destino
    def getHeuristicaM(Mapa:Array[Int]): Double = {
      var heuristica = 0.0;
      for(i <- 0 to (largo*largo)-1) {
        if (Mapa(i) != 0)
          heuristica = heuristica+Manhattan(i,Estaticos.getPos(Mapa(i))+1);
      }
      return heuristica;
    }
	//Heuristica de Euclides, cuanta la diagonal de distancia entre el elemento y la posicion destino
    def getHeuristicaE(Mapa:Array[Int]): Double = {
      var heuristica = 0.0;
      for(i <- 0 to Mapa.length-1) {
        if (Mapa(i) != 0)
          heuristica += Euclidean(i,Estaticos.getPos(Mapa(i))+1);
      }
      return heuristica;
    }	
	//Heuristica de Jaro
    def getHeuristicaJ(Mapa:Array[Int]): Double = {
      
      return Math.abs(Jaro(Mapa.mkString(" "),CustomMeta.mkString(" "))-1);
    }
	//H Jaro
    def Jaro(s1: String, s2: String): Double = {
        val s1_len = s1.length
        val s2_len = s2.length
        if (s1_len == 0 && s2_len == 0) return 1.0
        val match_distance = Math.max(s1_len, s2_len) / 2 - 1
        val s1_matches = Array.ofDim[Boolean](s1_len)
        val s2_matches = Array.ofDim[Boolean](s2_len)
        var matches = 0
        for (i <- 0 until s1_len) {
            val start = Math.max(0, i - match_distance)
            val end = Math.min(i + match_distance + 1, s2_len)
            start until end find { j => !s2_matches(j) && s1(i) == s2(j) } match {
                case Some(j) =>
                    s1_matches(i) = true
                    s2_matches(j) = true
                    matches += 1
                case None =>
            }
        }
        if (matches == 0) return 0.0
        var t = 0.0
        var k = 0
        0 until s1_len filter s1_matches foreach { i =>
            while (!s2_matches(k)) k += 1
            if (s1(i) != s2(k)) t += 0.5
            k += 1
        }
 
        val m = matches.toDouble
        (m / s1_len + m / s2_len + (m - t) / m) / 3.0
    }
	//Heuristica Manhattan
	
	def Manhattan(pos:Int,Num:Int): Double = {return Math.abs((pos / Math.sqrt(Puzzle.length.toDouble).toInt) - ((Num-1) / Math.sqrt(Puzzle.length.toDouble).toInt)) + Math.abs((pos % Math.sqrt(Puzzle.length.toDouble).toInt) - ((Num-1) % Math.sqrt(Puzzle.length.toDouble).toInt));}
	//Heuristica Euclides
	def Euclidean(pos:Int,Num:Int): Double = {return Math.sqrt(Math.pow(Math.abs((pos / Math.sqrt(Puzzle.length.toDouble).toInt) - ((Num-1) / Math.sqrt(Puzzle.length.toDouble).toInt)),2) + Math.pow(Math.abs((pos % Math.sqrt(Puzzle.length.toDouble).toInt) - ((Num-1) % Math.sqrt(Puzzle.length.toDouble).toInt)),2));}
	//Posicion del cero
	def getCero(Mapa:Array[Int]): Int ={
		for(i<- 0 to Mapa.length-1){if(Mapa(i)==0){return i;}}
		return -1;
	};
	//Heuristica hasta esta matriz
	def getG(): Double ={ return g;}
	//Heuristica de la matriz
	def getH(): Double ={ return h;}
	//Heuristia de la matriz, mas el costo hasta aca
	def getF(): Double ={ return getG()+getH();}
	//Indica el padre
	def getPadre(): Estado = { return Padre;}
	//Compara matrices (arreglos en el caso como se trabajo el proyecto)
	def Comparar(estado:Estado): Boolean = { return estado.Puzzle.equals(Puzzle);}
}

//Funciones que se requieren en distintos puntos 
object Estaticos{
	//Swap de elementos en una lista
	def Swap(Nums:Array[Int],Pos1:Int,Pos2:Int): Array[Int] = {
		var num = Nums(Pos1);
		Nums(Pos1) = Nums(Pos2);
		Nums(Pos2) = num;
		return Nums;
	}
	//Mover hacia arriba, null si no se puede
	def Arriba(Mapa:Estado): Estado = {if(Mapa.Cero>(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt)-1){return new Estado(Swap(Mapa.Puzzle.clone,Mapa.Cero,Mapa.Cero-(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt)),Mapa,Mapa.Cero-(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt))};return null;}
	//Mover hacia abajo, null si no se puede
	def Abajo(Mapa:Estado): Estado = {if(Mapa.Cero<(Mapa.Puzzle.length-(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt))){return new Estado(Swap(Mapa.Puzzle.clone,Mapa.Cero,Mapa.Cero+(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt)),Mapa,Mapa.Cero+(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt))};return null;}
	//Mover hacia derecha, null si no se puede
	def Derecha(Mapa:Estado): Estado = {if(Mapa.Cero%(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt)<(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt)-1){return new Estado(Swap(Mapa.Puzzle.clone,Mapa.Cero,Mapa.Cero+1),Mapa,Mapa.Cero+1);};return null;}
	//Mover hacia izquierda, null si no se puede
	def Izquierda(Mapa:Estado): Estado = {if(Mapa.Cero%(Math.sqrt(Mapa.Puzzle.length.toDouble).toInt)>0){return new Estado(Swap(Mapa.Puzzle.clone,Mapa.Cero,Mapa.Cero-1),Mapa,Mapa.Cero-1);};return null;}
    //Si una matriz tiene solucion
	def Solucionable(Numeros:List[Int]): Boolean = {
		var gridWidth = Math.sqrt(Numeros.length).toInt;
		var row = 0;
		var blankRow = 0;
		var parity = 0;
		for (i<- 0 to Numeros.length-1)
		    {
		        if (i % gridWidth == 0) { // advance to next row
		            row+=1;
		        }
		        if (Numeros(i) == 0) { // the blank tile
		            blankRow = row; // save the row on which encountered
		        }else{
		        for (j <- i + 1 to Numeros.length-1)
		        {
		            if (Numeros(i) > Numeros(j) && Numeros(j) != 0)
		            {
		                parity+=1;
		            }
		        }
			}
		    }
		    if (gridWidth % 2 == 0) { // even grid
		        if (blankRow % 2 == 0) { // blank on odd row; counting from bottom
		            return parity % 2 == 0;
		        } else { // blank on even row; counting from bottom
		            return parity % 2 != 0;
		        }
		    } else { // odd grid
		        return parity % 2 == 0;
		    }
	}
	//Inicia numeros solucionables
	def IniciarNumeros(Num:Int): Array[Int] = {
		var Posiciones = (0 to Num*Num-1).toList;
		Posiciones = util.Random.shuffle(Posiciones);
		while(!Solucionable(Posiciones)){
			Posiciones = util.Random.shuffle(Posiciones);
		}
		return Posiciones.toArray;
	}
	//Indica la posicion de un numero 
	def getPos(Num:Int): Int = {
		var c = 0;
		for(a <- CustomMeta){
			if(a == Num){ return c;};c+=1;
		}
		return -1;
	}
	//Compara Listas
	def CompararArreglos(M1:Array[Int],M2:Array[Int]):Boolean={return (M1: Seq[Int]) == (M2: Seq[Int]);}
	//Ordena una tupla de (Estado,Heuristica), dependiendo la heuristica
	def sortLists(E:List[(Estado,Double)]): List[(Estado,Double)] = {
		return scala.util.Sorting.stableSort(E,(e1: (Estado, Double), e2: (Estado, Double)) => e1._2 < e2._2).toList;
	}
}

//Arma y soluciona la matriz
class Armar(){
	//Crea El padre e inicia la solucion 
	def Iniciar(){
		var Raiz = new Estado(NumDefault.toArray);
		var Actual = Raiz;
		solucion(Actual);
	}
	//Soluciona la matriz
	def solucion(Act:Estado){
		var Actual = Act;
		//Contador de tiempo
		val t0 = System.currentTimeMillis();
		//Lista de nodos abiertos
		var Abierto = List[(Estado,Double)]();
		//Lista de nodos cerrados
		var Cerrado = List[(Estado,Double)]();
		//Agrega el nodo Padre a la lista de abiertos para iniciar la busqueda
		Abierto=Abierto++List((Actual,Actual.getF()));
		//El contadorcito de los noditos
		var contadorcito = 0;
		//Ciclo en busca de solucion, se detiene si no hay mas nodos abiertos o encuentra la solucion
		while(!Abierto.isEmpty){
			//Aumenta contador
			contadorcito+=1;
			//Ordena la lista de nodos abiertos
			Abierto = Estaticos.sortLists(Abierto);
			//Obtiene la cabeza de los nodos abiertos, el cual es el que posee la menor heuristica
			Actual = Abierto.head._1;
			//Elimina el elemento de la lista de abiertos
			Abierto = Abierto.tail;
			//Si la heuristica es cero, quiere decir que es la solucion
			if(Actual.getHeuristica()==0){
				var cont=0;
				//Termina el tiempo
				val t1 = System.currentTimeMillis();
				var Pila = new scala.collection.mutable.Stack[Array[Int]]();
				var Heur = 0.0;
				//Invierte la solucion para mostrarla en orden
				while(Actual!=null){
					if(Heur == 0){ Heur = Actual.getF(); }
					Pila.push(Actual.Puzzle);
					Actual = Actual.Padre;
					cont+=1;
				}
				while(!Pila.isEmpty){
					printMatrizFormat(Pila.pop());
				}
				var Segundos = ((t1 - t0)/1000)%60 + "s ";
				var MiliSegundos = (t1 - t0)%1000 + "ms";
				var Minutos = "";
				if(((t1-t0)/60000).toInt>1){
					Minutos = ((t1-t0)/60000)+"m "
				}
				println("Pasos: "+cont);
				println("Heuristica: " + Heur)
				println("Duracion: " + Minutos+Segundos+MiliSegundos)
				println("Nodos visitados: "+contadorcito);
				return;
			}
			//Revisa los movimientos validos
			for(a <- 0 to 3){
				var sucesor = new Estado((0 to (largo*largo)-1).toArray);
				sucesor = null;
				//Hace el movimiento segun el paso del ciclo
				if(a == 0){sucesor = Estaticos.Arriba(Actual);}
				if(a == 1){sucesor = Estaticos.Abajo(Actual);}
				if(a == 2){sucesor = Estaticos.Derecha(Actual);}
				if(a == 3){sucesor = Estaticos.Izquierda(Actual);}
				//Si es null el movimiento era invalido
				if(sucesor!=null){
					//Revisa si ya existe en la lista de nodos abiertos y si es mayor la heuristica existente lo descarta, si es menor lo reemplaza
					var tmp = modificarAC(sucesor,Abierto);
					sucesor = tmp._1;
					Abierto = tmp._2;
					//Revisa si ya existe en la lista de nodos Cerrados y si es mayor a la heuristica existente lo descarta, si es menor lo reemplaza
					tmp = modificarAC(sucesor,Cerrado);
					sucesor = tmp._1;
					Cerrado = tmp._2;
					//Lo agrega a la lista de abiertos si no fue descartado
					if(sucesor!=null){Abierto :+=(sucesor,sucesor.getF())}
					
				}	
			}
			
			
			Cerrado:+=(Actual,Actual.getF());
		}
		println("Wow, mas de "+contadorcito+" nodos visitados y no encontramos la Solucion");
	}
	//Revisa si existe en la lista y si la heuristica es menor a la existente, si es menor lo reemplaza, si es mayor lo descarta y si no existe lo agregara
	def modificarAC(sucesor:Estado,Abierto:List[(Estado,Double)]):(Estado,List[(Estado,Double)])={
		if(Abierto.length == 0 || sucesor == null){ 
			return (sucesor,Abierto);
		}
		var nAbierto = Abierto;
		var flag = true;
		val t2 = System.currentTimeMillis();
		var c = 0;
		var b = false;
		Abierto.foreach{x=> if(Estaticos.CompararArreglos(sucesor.Puzzle,x._1.Puzzle)){b = true;return (null,Abierto);}else{c+=1;}};
		if(b){
			if(Abierto(c)._2>sucesor.getF()){
				nAbierto = nAbierto.slice(0,c);
				nAbierto = nAbierto++ Abierto.slice(c+1,Abierto.length);
				return (sucesor,nAbierto);
			}else{flag=false;}
		}
		if(flag){
			return (sucesor,Abierto);	
		}else{
			return (null,Abierto);
		}
	}
	//Imprime en formato de matriz
	def printMatrizFormat(N:Array[Int]){
		for (a <- 0 to N.length-1){
			if(a%Math.sqrt(N.length.toDouble).toInt == 0 && a!=0){println()}
			print(N(a).toString + " ");
		}
		println()
		println()
	}
}
//Inicia el proceso
Main.main(args);