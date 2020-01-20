<?php
	$r = fgets(fopen("php://stdin", "r"));
	preg_match_all("/[A-Z]/", $r, $matches);
	print(implode("", $matches[0]));
