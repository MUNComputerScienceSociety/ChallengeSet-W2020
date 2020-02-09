<?php
	$ar_1 = ["A#"=>"Bb", "C#"=>"Db", "D#"=>"Eb", "F#"=>"Gb", "G#"=>"Ab"];
	$ar_2 = array_flip($ar_1);
	$f = fopen("php://stdin", "r");
	$c = 0;
	while(($r = fgets($f)) !== false)
	{
		$c++;
		$s = "";
		$b = explode(" ", trim($r));
		if(isset($ar_1[$b[0]]))
			$s .= $ar_1[$b[0]];
		elseif(isset($ar_2[$b[0]])) {
			$s .= $ar_2[$b[0]];
		}
		
		if($s == "")
			$s = "UNIQUE";
		else
			$s .= " " . $b[1];
		print("Case " . $c . ": " . $s . PHP_EOL);
	}
