<?php
include "connectdb.php";
error_reporting(E_ALL);

//Get the variables here
$postdata = file_get_contents("php://input");
$request = json_decode($postdata);
@$username = $request->username;
@$password = $request->password;


//Get the variables here end
$insertstatement = 'SELECT count(*) co FROM estudiante WHERE correoElectronico="'.$username.'" AND contraseña="'.$password.'"';


$rs=$dbhandle->query($insertstatement);


while ($row = $rs->fetch_array()) {
  $data[] = $row;
}

$obj = json_encode($data);
$co = (int)$obj[16];

if($co == 1){
	echo json_encode($co);
}

else{
		//Get the variables here end
		$insertstatement = 'SELECT count(*) co FROM profesor WHERE correoElectronico="'.$username.'" AND contraseña="'.$password.'"';


		$rs=$dbhandle->query($insertstatement);


		while ($row = $rs->fetch_array()) {
		  $data2[] = $row;
		}

		

		$obj = json_encode($data2);
		$decode3= json_decode($obj,true);

		$co = $decode3[0]["co"];
		
		if($co == 1){
			echo json_encode(2);

		}
		else{
			echo json_encode($co);
		}

		
}

?>