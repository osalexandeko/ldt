<?php session_start(); ?>
<?php //echo "PHP: <br>"; ?> 




<?php


switch(trim($_GET[status])){
	case "info": 
		echo "info";
		//echo file_put_contents("log.txt","info\r\n",FILE_APPEND);
		break;
	case "json":
		
	$myObj->name = "John";
	$myObj->age = 30;
	$myObj->city = "Ashqelon";
	$myJSON = json_encode($myObj);
	echo $myJSON;

		break;	
	default:	
		/*file_put_contents("log.txt","default\r\n",FILE_APPEND);*/
		break;
	 
	
}

//echo session_id();


//echo shell_exec("cat log.txt");

?>