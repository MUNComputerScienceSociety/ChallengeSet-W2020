<?php
	$in = explode(" ", fgets(fopen("php://stdin", "r")));
	$s = array_pop($in);
	$f = array_pop($in);
	for($i = 1; $i < count($in); $i++) {
		for($j = $i + 1; $j < count($in); $j++) {
			if($in[0] + $in[$i] + $in[$j] == $f || $in[0] + $in[$i] + $in[$j] == $s) {
				$fbox = [$in[0], $in[$i], $in[$j]];
				$sbox = array_diff($in, $fbox);
				break;
			}
		}
		if(isset($fbox)) break;
	}
	if(array_sum($fbox) == $s) list($fbox, $sbox) = [$sbox, $fbox];
	arsort($fbox); arsort($sbox);
	print(implode(" ", array_merge($fbox,$sbox)));
