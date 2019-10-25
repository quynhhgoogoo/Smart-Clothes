<?php
include "php_serial.class.php";

/*Display all php errors and warnings*/
error_reporting(E_ALL);
/*display_errors : determine if errors will be displayed or hidden to user*/
ini_set("display_errors", 1);

define("PORT", "/dev/insert_port_path_here");

/*Open the connection to devices, send a message and wait for response from device*/
$serial = new phpSerial;
$serial -> deviceSet(PORT);
$serial->confBaudRate(9600);
$serial->confParity("none");
$serial->confStopBits(1);
$serial->confCharacterLength(8);
$serial->confFlowControl("none");

$stringa[0]=0;      /*temperature*/
$stringa[1]=0;      /*hudminity*/
$stringa[2]=0;      /*speed*/
$stringa[3]=0;      /*distance*/
$stringa[4]=0;      /*calories burnt*/
$stringa[5]=0;      /*steps counted*/

$serial -> deviceOpen();
$serial -> sendMessage("y");
$read = $serial -> readPort();
$stringa = explode('#', $read);
$serial->deviceClose();
?>

<!DOCTYPE html>
<html>
	<head>
		<title>Smart Clothes</title>
	</head>
	
	<body>
		<h1>Your health data tracking</h1>
		<table align="left" width="500px">
			<tr>
				<td>Temperature</td>
				<td>Hudminity</td>
				<td>Speed</td>
				<td>Distance</td>
				<td>Calories</td>
				<td>Steps</td>
			</tr>
			<tr>
				<td><?php print $string[0]; ?></td>
				<td><?php print $string[1]; ?></td>
				<td><?php print $string[2]; ?></td>
				<td><?php print $string[3]; ?></td>
				<td><?php print $string[4]; ?></td>
				<td><?php print $string[5]; ?></td>
			</tr>
		</table>
		<br><br><br>
		<form <?php echo $_SERVER['PHP_SELF']; ?> method="get">
			<input type="submit" name="REFRESH" value="REFRESH">
		</form>
	</body>
</html>