<?php

include "connectdb.php";
  
 $data = json_decode(file_get_contents("php://input")); 
 $Correo = $dbhandle->real_escape_string($data->Correo); 
 $Curso = $dbhandle->real_escape_string($data->Curso);

$insertstatement = 'SELECT idEstudiante  FROM Estudiante WHERE correoElectronico="'.$Correo.'"';
$rs=$dbhandle->query($insertstatement);

while ($row = $rs->fetch_array()) {
  $data2[] = $row;
}		

$obj = json_encode($data2);
$decode3= json_decode($obj,true);

$co = $decode3[0]["idEstudiante"];

$insertstatement2 = 'SELECT idCurso FROM Curso WHERE nombre="'.$Curso.'"';

$rss=$dbhandle->query($insertstatement2);

while ($row2 = $rss->fetch_array()) {
  $data3[] = $row2;
}

$obj1 = json_encode($data3);
$decode4= json_decode($obj1,true);

$co2 = $decode4[0]["idCurso"];

$insertstatement3 = 'SELECT Profesor_idProfesor FROM calificacion_curso WHERE Curso_idCurso = "'.$co2.'" AND Estudiante_idEstudiante = "'.$co.'"';

$rsss=$dbhandle->query($insertstatement3);
while ($row3 = $rsss->fetch_array()) {
  $data4[] = $row3;
}

$obj2 = json_encode($data4);
$decode5= json_decode($obj2,true);

$co3 = $decode5[0]["Profesor_idProfesor"];

$insertstatement4 = 'CALL `mydb`.`ver_calificaciones_curso`('.$co2.', '.$co3.', '.$co.');';
$rssss=$dbhandle->query($insertstatement4);

while ($row4 = $rssss->fetch_array()) {
  $data5[] = $row4;
}
print json_encode($data5); 
 

?>