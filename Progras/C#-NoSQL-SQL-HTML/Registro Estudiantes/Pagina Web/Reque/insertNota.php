<?php
include "connectdb.php";
  
 $data = json_decode(file_get_contents("php://input")); 
 
 $Correo = $dbhandle->real_escape_string($data->Correo);     
 $Profesor = $dbhandle->real_escape_string($data->Profesor); 
 $Curso = $dbhandle->real_escape_string($data->Curso);
 $idAsignacion= $dbhandle->real_escape_string($data->Asignacion);
 $Nota= $dbhandle->real_escape_string($data->Nota);




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





$insertstatement3 = 'SELECT idEstudiante  FROM estudiante WHERE correoElectronico="'.$Correo.'"';


$rs3=$dbhandle->query($insertstatement3);

while ($row3 = $rs3->fetch_array()) {
  $data4[] = $row3;
}		

$obj3 = json_encode($data4);
$decode3= json_decode($obj3,true);

$idEst = $decode3[0]["idEstudiante"];


$query='CALL `mydb`.`ver_IDcalificaciones_curso`('.$idCur.','.$idPro.','.$idEst.','.$idAsignacion.');';


$rs4=$dbhandle->query($query);

while ($row4 = $rs4->fetch_array()) {
  $data5[] = $row4;
}		

$obj4 = json_encode($data5);
$decode4= json_decode($obj4,true);

$idNota = $decode4[0]["idCalificacion"];

print $idNota;
print ",";
print $Nota;
?>



