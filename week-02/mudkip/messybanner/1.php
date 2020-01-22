<?php
	$input = fopen("php://stdin", "r");
	$toprint = "";
	while(($line = fgets($input)) !== false) {
		if(preg_match("/^[A-Z]{1}([A-Z]|\s){2}[0-9]{4}[A-Z]?$/", $line))
			$toprint.= "Y";
		else
			$toprint.= "N";
	}
	print(substr(chunk_split($toprint, 1), 0, -2));
