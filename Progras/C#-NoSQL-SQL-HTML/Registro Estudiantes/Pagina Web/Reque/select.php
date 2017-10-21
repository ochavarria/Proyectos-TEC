<?php
//database settings
include "connectdb.php";

$query="select * from estudiante";

$rs=$dbhandle->query($query);

while ($row = $rs->fetch_array()) {
  $data[] = $row;
}

    print json_encode($data);
?>


