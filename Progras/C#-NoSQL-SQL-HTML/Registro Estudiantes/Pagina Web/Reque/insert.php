<?php
include "connectdb.php";
  
 $data = json_decode(file_get_contents("php://input"));  
     
  $Nombre = $dbhandle->real_escape_string($data->Nombre); 
  $Apellido = $dbhandle->real_escape_string($data->Apellido); 
  $Correo = $dbhandle->real_escape_string($data->Correo);
  $Contra=$dbhandle->real_escape_string($data->Contra);

  $query="INSERT INTO estudiante(nombre,apellido,correoElectronico,contraseña) VALUES ('$Nombre','$Apellido','$Correo','$Contra')";

  $dbhandle->query($query) 

 ?>