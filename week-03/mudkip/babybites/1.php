<?php
	$f = fopen("php://stdin", "r");
	$c = fgets($f);
	$words = explode(" ", trim(fgets($f)));
	for($i=0; $i<$c; $i++) {
		if($words[$i] != $i+1 && $words[$i] != "mumble")
			exit("something is fishy");
	}
	print("makes sense");
