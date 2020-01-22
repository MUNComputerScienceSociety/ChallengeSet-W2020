<?php
        $f = fopen("php://stdin", "r");
	$c = (int)fgets($f);
	for($i = 0; $i < $c; $i++) {
		$nums = explode(" ", fgets($f));
		print(((
			$nums[0]*$nums[1] == $nums[2]
			|| $nums[0]+$nums[1] == $nums[2]
			|| abs($nums[0]-$nums[1]) == $nums[2]
			|| $nums[0]/$nums[1] == $nums[2]
			|| $nums[1]/$nums[0] == $nums[2]
		) ? "Possible" : "Impossible") . ($i != $c-1 ? PHP_EOL : ""));
	}
