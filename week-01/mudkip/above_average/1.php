<?php

$in = fopen('php://stdin', 'r');
$lines = (int)fgets($in);

for($i = 0; $i < $lines; $i++) {
	$g = explode(" ", fgets($in));
	$c = array_shift($g);
	$avg = array_sum($g)/$c;
	$above_avg = array_filter($g, function($val) use ($avg) { return $val > $avg; });
	printf("%.3f%%" . (($i == $lines-1) ? "" : PHP_EOL), (count($above_avg)/$c)*100);
}
