<?php
	$in = fgets(fopen("php://stdin", "r"));
	$t = substr_count($in, "T");
	$c = substr_count($in, "C");
	$g = substr_count($in, "G");
	print($t**2+$c**2+$g**2+(min([$t,$c,$g])*7));
