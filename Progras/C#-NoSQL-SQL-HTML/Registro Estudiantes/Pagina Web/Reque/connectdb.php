<?php
define("HOSTNAME","localhost");
define("USERNAME","root");
define("PASSWORD","root");
define("DATABASE","mydb");

$dbhandle=new mysqli(HOSTNAME,USERNAME,PASSWORD,DATABASE) or die("Unable to Connect DB");

?>