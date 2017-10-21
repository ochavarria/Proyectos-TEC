<?php

include "connectdb.php";
  
 $data = json_decode(file_get_contents("php://input")); 
 

 $idNota= $dbhandle->real_escape_string($data->id2);
 $Nota= $dbhandle->real_escape_string($data->Nota2);
 print($idNota);
 print $Nota;
$xxx='CALL mydb.update_nota_individual('.$idNota.','.$Nota.');';
print $xxx;
$dbhandle->query($xxx);
?>


