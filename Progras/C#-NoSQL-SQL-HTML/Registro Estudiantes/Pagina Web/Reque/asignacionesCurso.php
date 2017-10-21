<?php
include "connectdb.php";
  
 $data = json_decode(file_get_contents("php://input")); 
 
     
 $Profesor = $dbhandle->real_escape_string($data->Profesor); 
 $Curso = $dbhandle->real_escape_string($data->Curso);
 

$insertstatement = 'SELECT idProfesor  FROM profesor WHERE correoElectronico="'.$Profesor.'"';


$rs=$dbhandle->query($insertstatement);

while ($row = $rs->fetch_array()) {
  $data2[] = $row;
}		

$obj = json_encode($data2);
$decode= json_decode($obj,true);

$idPro = $decode[0]["idProfesor"];



$insertstatement2 = 'SELECT idCurso  FROM curso WHERE nombre="'.$Curso.'"';


$rs2=$dbhandle->query($insertstatement2);

while ($row2 = $rs2->fetch_array()) {
  $data3[] = $row2;
}		

$obj2 = json_encode($data3);
$decode2= json_decode($obj2,true);

$idCur = $decode2[0]["idCurso"];


$query = 'CALL `mydb`.`ver_asignaciones_curso`('.$idCur.','.$idPro.')';		
$rss=$dbhandle->query($query);

while ($row2 = $rss->fetch_array()) {
  $data4[] = $row2;
}

print json_encode($data4	);

//'CALL `mydb`.`ver_asignaciones_curso`('.$idCur.','.$idPro.')';
?>


