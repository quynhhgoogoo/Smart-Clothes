<?php 
    $server = "mysql.cc.puv.fi";
    $user = "e1601128";
    $pwd = "XkJuRzUxEPe5";
    $db = "e1601128_smart_clothes";

    $string[0]="0";
    $string[1]="0";
    $string[2]="0";
    $string[3]="0";
    $string[4]="0";
    $string[5]="0";

    $con = mysql_connect($server, $user, $pwd);
    if(!$con)
        die(mysql_error());
    $datab = mysql_select_db();

    if(!$datab)
        die(mysql_error);
    $row = mysql_fetch_array($result) or die(mysql_error());
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
				<td><?php echo $row['TEMP']; ?></td>
				<td><?php echo $row['TEMP']; ?></td>
				<td><?php echo $row['TEMP']; ?></td>
                <td><?php echo $row['TEMP']; ?></td>
                <td><?php echo $row['TEMP']; ?></td>
                <td><?php echo $row['TEMP']; ?></td>
			</tr>
		</table>
		<br><br><br>
		<form <?php echo $_SERVER['PHP_SELF']; ?> method="get">
			<input type="submit" name="REFRESH" value="REFRESH">
		</form>
	</body>
</html>