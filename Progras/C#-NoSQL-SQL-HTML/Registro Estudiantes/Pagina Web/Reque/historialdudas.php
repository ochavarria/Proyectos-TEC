<?php

include "connectdb.php";
  
 $data = json_decode(file_get_contents("php://input")); 
 $Correo = $dbhandle->real_escape_string($data->Correo); 

$insertstatement = 'SELECT idEstudiante  FROM Estudiante WHERE correoElectronico="'.$Correo.'"';
$rs=$dbhandle->query($insertstatement);

while ($row = $rs->fetch_array()) {
  $data2[] = $row;
}		

$obj = json_encode($data2);
$decode3= json_decode($obj,true);

$co = $decode3[0]["idEstudiante"];

$insertstatement2 = 'CALL `mydb`.`ver_historial_dudas`('.$co.');';
$rss=$dbhandle->query($insertstatement2);

while ($row2 = $rss->fetch_array()) {
  $data3[] = $row2;
}
print json_encode($data3); 
 

?>