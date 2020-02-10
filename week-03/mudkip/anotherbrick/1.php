<?php
	$f = fopen("php://stdin", "r");
	list($h, $w, $b) = explode(" ", trim(fgets($f)));
	$d = explode(" ", trim(fgets($f)));
	$or_w = $w;
	$bc = 0;
	while($h > 0)
	{
		if($w < 0 || ($w > 0 && $b == 0)) {
			exit("NO");
		}
		if($w == 0) {
			$h--;
			$w = $or_w; 
		}
		$b--;
		$w-=$d[$bc];
		$bc++;
	}
	print("YES");
