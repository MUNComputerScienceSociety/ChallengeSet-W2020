<?php
	$f = fopen("php://stdin", "r");
	$c = (int)fgets($f);
	for($i = 0; $i < $c; $i++) {
		print(strlen(trim(fgets($f))) . ($i != $c-1 ? PHP_EOL : ""));
	}
